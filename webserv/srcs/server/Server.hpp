#ifndef SERVER_HPP
#define SERVER_HPP

class Server;

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <iomanip>
#include <sys/time.h>
#include "../parsing/configserv.hpp"
#include "../request/Client.hpp"
#include "../request/request.hpp"
#include "ListenSocket.hpp"
#include "../request_handler/redirection.hpp"
#include "../response/response.hpp"
#include "../request_handler/Handler.hpp"
#define TIMEOUT_LIMIT 60
#define MAX_WRITE_SIZE static_cast<size_t>(600000)


class Server
{
private:
	std::vector<ListenSocket> _ListenSockets;
	std::vector<Client> _Clients;
	// std::map<int, ListenSocket>	_listen_sd_map;
	std::map<int, Client> _client_sds_map;
	fd_set _read_sds;
	fd_set _write_sds;
	int _max_sd;
	Server(void);

public:
	Server(std::vector<configserv> configservs);
	~Server(void);
	Server(const Server &copy);

	Server &operator=(const Server &ref);
	void set_server(void);
	void run_server(void);
	bool add_client(ListenSocket &listen_socket);
	void read_socket(Client &client);
	void write_socket(Client &client);
	void check_timeout(void);
};

#endif
