#include "Server.hpp"

// ------------------- Constructors -------------------

Server::Server(void)
{
	std::cout << "New Server called" << std::endl;
}

Server::Server(std::vector<configserv> config_servs) : _max_sd(0)
{
	int nb_ports;
	for (unsigned int i = 0; i < config_servs.size(); ++i)
	{
		nb_ports = (config_servs[i].getListen()).size();
		for (int i_port = 0; i_port != nb_ports; i_port++)
		{
			ListenSocket curr_listen_socket(config_servs[i], config_servs[i].getListen()[i_port]);
			this->_ListenSockets.push_back(curr_listen_socket);
		}
	}
}

Server::~Server(void)
{
}

Server::Server(const Server &copy)
{
	*this = copy;
}

Server &Server::operator=(const Server &ref)
{
	if (this != &ref)
	{
	}
	return *this;
}

void Server::set_server(void)
{
	int current_fd;
	// Clear the socket set to void
	FD_ZERO(&this->_read_sds);
	FD_ZERO(&this->_write_sds);
	for (std::vector<ListenSocket>::iterator it = this->_ListenSockets.begin(); it != this->_ListenSockets.end(); ++it)
	{
		it->initSocket();
		current_fd = it->get_listen_fd();
		// Set new socket as non blocked
		fcntl(current_fd, F_SETFL, O_NONBLOCK);
		// Add every listen sockets to set
		FD_SET(current_fd, &this->_read_sds);
		// Save the max socket descriptor for forther use
		if (current_fd > this->_max_sd)
			this->_max_sd = current_fd;
		std::cerr << "   IP : " << std::setw(14) << std::left << it->get_host() << " port : " << it->get_port() << " fd :" << it->get_listen_fd() << std::endl;
	}
	std::cerr << ">> Max fd : " << this->_max_sd << std::endl;
}

void Server::run_server(void)
{
	fd_set temp_read_sds;
	fd_set temp_write_sds;

	std::cout << std::endl
			  << "##################" << std::endl
			  << "# SERVER STARTED #" << std::endl
			  << "##################" << std::endl;
	while (1)
	{
		FD_ZERO(&temp_read_sds);
		FD_ZERO(&temp_write_sds);
		temp_read_sds = this->_read_sds;
		temp_write_sds = this->_write_sds;

		// Wait for an activity on one of the , select return the value of readies FD
		if (select(this->_max_sd + 1, &temp_read_sds, &temp_write_sds, NULL, NULL) < 0)
			exit(1);
		for (unsigned int i = 0; i < this->_ListenSockets.size(); ++i)
		{
			if (FD_ISSET(this->_ListenSockets[i].get_listen_fd(), &temp_read_sds))
				if (this->add_client(_ListenSockets[i]))
					continue;
		}

		for (int i = 4; i <= this->_max_sd; ++i)
		{
			// if (_client_sds_map.count(i))
			//   std::cout << " " << this->_client_sds_map[i].get_fd();
			if (_client_sds_map.count(i) && FD_ISSET((this->_client_sds_map[i]).get_fd(), &temp_read_sds))
				read_socket(this->_client_sds_map[i]);
		}
		// std::cout << std::endl;
		for (int i = 4; i <= this->_max_sd; ++i)
		{
			if (_client_sds_map.count(i) && FD_ISSET((this->_client_sds_map[i]).get_fd(), &temp_write_sds))
				write_socket(this->_client_sds_map[i]);
		}
		check_timeout();
	}
	std::cerr << "SERVER END " << std::endl
			  << std::endl;
}

bool Server::add_client(ListenSocket &listen_socket)
{
	struct sockaddr_in address;
	int addrlen;
	int new_socket;
	bool socket_exist = false;

	memset(&address, 0, sizeof(address));
	addrlen = sizeof(address);
	new_socket = accept(listen_socket.get_listen_fd(), (struct sockaddr *)&address, (socklen_t *)&addrlen);
	if (new_socket == -1)
	{
		std::cerr << "Issue accepting new_socket :" << new_socket
				  << " " << listen_socket.get_listen_fd() << std::endl;
		exit(1);
	}

	// Set new socket as non blocked
	if (fcntl(new_socket, F_SETFL, O_NONBLOCK) < 0)
	{
		std::cerr << "Issue setting O_NONBLOCK" << std::endl;
		exit(1);
	}
	Client new_client(new_socket, listen_socket);
	// ------------- Message for testing
	std::cout << std::endl
			  << "|" << std::endl
			  << "|   New connection: socket fd is " << new_socket << " | "
			  << inet_ntoa(address.sin_addr) << " | " << ntohs(address.sin_port) << "/" << std::endl
			  << "|" << std::endl;

	// Add new socket to fd_set
	if (new_socket > this->_max_sd)
		this->_max_sd = new_socket;
	if (_client_sds_map.count(new_socket) != 0)
	{
		if (FD_ISSET(new_socket, &this->_read_sds))
			FD_CLR(new_socket, &this->_read_sds);
		if (FD_ISSET(new_socket, &this->_write_sds))
			FD_CLR(new_socket, &this->_write_sds);
		_client_sds_map.erase(new_socket);
		socket_exist = true;
	}
	FD_SET(new_socket, &this->_read_sds);
	if (_client_sds_map.count(new_socket) != 0)
		_client_sds_map.erase(new_socket);
	this->_client_sds_map[new_socket] = new_client;
	return socket_exist;
}

void Server::read_socket(Client &client)
{
	Redirection redirect;
	int socket = client.get_fd();

	client.setTimeout();

	try
	{
		if (client.getFlag() == PARSING_REQUEST)
			client.getReq()->parseRequest(socket);

		if (client.getFlag() == EXPECTING)
		{
			FD_CLR(socket, &this->_read_sds);
			FD_SET(socket, &this->_write_sds);
		}

		if (client.getFlag() == PREPARING_RESPONSE)
		{
			client.getResponse()->setConnectionType(client.getKeepAlive());
			client.getResponse()->setHTTPVersion(client.getReq()->getHttpVersion());
			redirect.path(*client.getReq(), *client.getResponse());

			FD_CLR(socket, &this->_read_sds);
			FD_SET(socket, &this->_write_sds);
		}
	}
	catch (const ErrorWebServ &e)
	{
		// std::cerr << "####### Client :"  << std::endl;
		std::cerr << "Error(" << e.getErrorCode() << "): " <<  e.what()<< std::endl;
		client.setKeepAlive(false);
		client.getResponse()->setStatusCode(e.getErrorCode());
		client.getResponse()->setStatusMessage(e.what());
		std::stringstream ss;
		ss << e.getErrorCode();
		if (client.get_listen_socket().get_error().compare(ss.str()) == 0)
			client.getResponse()->ErrorBody(e.getErrorCode(), client, true);
		else
			client.getResponse()->ErrorBody(e.getErrorCode(), client, false);
		client.getResponse()->setConnectionType(false);
		client.getResponse()->setContentType("text/html");
		client.setFlag(RESPONSE_OK);
		FD_CLR(socket, &this->_read_sds);
		FD_SET(socket, &this->_write_sds);
	}
}

void Server::write_socket(Client &client)
{
	int socket = client.get_fd();
	client.setTimeout();
	ssize_t written = 0;

	if (client.getFlag() == WRITING_RESPONSE)
	{
		if (client.getResponse()->getHeadersWritten())
		{
			if (!client.getResponse()->getBuffer().empty())
			{
				written = send(socket, client.getResponse()->getBuffer().c_str(), client.getResponse()->getBuffer().size(), 0);
				client.getResponse()->setBuffer("");
				client.getResponse()->updateBytesWritten(written);
			}
			else
			{
				try
				{
					std::string buffer = readOnce(client.getResponse()->getFD());
					written = send(socket, buffer.c_str(), buffer.size(), 0);
					if (static_cast<ssize_t>(buffer.size()) != written && written > 0)
					{
						std::string remaining = buffer.substr(written);
						client.getResponse()->setBuffer(remaining);
					}
					client.getResponse()->updateBytesWritten(written);
					if (client.getResponse()->getBytesWritten() >= client.getResponse()->getFileSize())
					{
						close(client.getResponse()->getFD());
						client.setFlag(FINISHED);
					}
				}
				catch (const ErrorWebServ &e)
				{
					written = -1;
				}
			}
		}
		if (!client.getResponse()->getHeadersWritten())
		{
			written = send(socket, client.getResponse()->getResp().c_str(), client.getResponse()->getResp().length(), 0);
			client.getResponse()->setTrueHeadersWritten();
		}
	}

	if (client.getFlag() == RESPONSE_OK) // all the body was processed
	{
		if (client.getReq()->getHasReturn())
			client.getResponse()->setStatusCode(301);
		client.getResponse()->formatResponse(client, *client.getReq());
		written = send(socket, client.getResponse()->getResp().c_str(), client.getResponse()->getResp().length(), 0);
		client.setFlag(FINISHED);
	}


	if (client.getFlag() == EXPECTING)
	{
		written = send(socket, client.getResp().c_str(), client.getResp().length(), 0);
		client.setResp(""); // Nettoyer la réponse
		client.setFlag(PARSING_REQUEST);
		client.getReq()->setStatus(PARSING_BODY);
		FD_CLR(socket, &this->_write_sds);
		FD_SET(socket, &this->_read_sds);
	}

	if (written <= 0)
	{
		if (client.getFlag() == WRITING_RESPONSE)
			close(client.getResponse()->getFD());
		FD_CLR(socket, &this->_write_sds);
		close(socket);
		this->_client_sds_map.erase(socket);
		return;
	}

	if (client.getFlag() == FINISHED)
	{
		FD_CLR(socket, &this->_write_sds);
		if (client.getKeepAlive()) // status is inherited from Request parsing
		{
			FD_SET(socket, &this->_read_sds);
			client.reUseClient();
		}
		else
		{
			this->_client_sds_map.erase(socket);
			close(socket);
		}
	}
	return;
}

void Server::check_timeout(void)
{
	for (int i = 0; i <= this->_max_sd; ++i)
	{
		if (_client_sds_map.count(i) && (time(NULL) - _client_sds_map[i].get_connected_time() > TIMEOUT_LIMIT))
		{
			// std::cerr << "Disconnection from client fd : " << i << " sec asgo " << time(NULL) - _client_sds_map[i].get_connected_time() << std::endl;
			if (FD_ISSET(i, &_read_sds))
				FD_CLR(i, &_read_sds);
			if (FD_ISSET(i, &_write_sds))
				FD_CLR(i, &_write_sds);
			if (i >= _max_sd)
				_max_sd--;
			close(i);
			_client_sds_map.erase(i);
		}
	}
}
