#ifndef LISTENSOCKET_HPP
#define LISTENSOCKET_HPP

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <cstring>
#include "../parsing/configserv.hpp"

#define MESSAGE_BUFFER 10000000
#define MAX_CLIENTS 30

class ListenSocket
{
private:
	int _listen_sd;
	int _port;
	struct sockaddr_in _address;
	std::string _name;
	std::string _host;
	std::string _root;
	bool _autoindex;
	unsigned int _client_size;
	std::string _index;
	std::string _error;
	std::map<std::string, std::string> _errorpath;
	std::vector<std::string> _allow_methods;
	std::map<std::string, location> _location;

public:
	ListenSocket(void);
	ListenSocket(configserv config_serv, int port);
	~ListenSocket(void){};
	ListenSocket(const ListenSocket &copy);

	ListenSocket &operator=(const ListenSocket &ref);

	void initSocket(void);

	int get_listen_fd(void);
	struct sockaddr_in get_address(void);
	int get_port(void);
	std::string get_root(void);
	std::string get_host(void);
	std::string get_name(void);
	bool get_autoindex() const;
	unsigned int get_clientSize() const;
	std::string get_index() const;
	std::string get_error() const;
	std::map<std::string, std::string> get_error_path() const;
	std::vector<std::string> get_allow_methods() const;
	std::map<std::string, location> get_location() const;
};

#endif
