#pragma once

#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "../request/request.hpp"
#include "../response/response.hpp"
#include <sys/wait.h>

#define BUFFER 1000

class CgiHandler
{
	private:
		std::string _body;
		std::map<std::string, std::string> _env;

		void initenv(Request &request);
		char **EnvToArray() const;
	public:
		CgiHandler(Request &request);
		~CgiHandler();
		
		std::string execute(std::string Script, Response &resp);

        class InternalServerError : public ErrorWebServ
        {
            public:
                InternalServerError(int errorCode) : ErrorWebServ(errorCode) {}
                const char *what() const throw();
        };
};
