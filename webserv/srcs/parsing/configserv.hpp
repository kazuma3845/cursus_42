#pragma once

class configserv;

# include <iostream>
# include <string>
# include <algorithm>
# include <fstream>
# include <sstream>

# include <map>
# include <vector>

# include "location.hpp"

// using namespace std;

class configserv
{
	private:
		std::vector<int> _listen;
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
		configserv();
		~configserv(){};

		//additional fonction
		void serv(std::vector< std::vector<std::string> > file, unsigned int &i);
		void checkReturn(void);
		//GET
		std::vector<int> getListen() const;
		std::string getName() const;
		std::string getHost() const;
		std::string getRoot() const;
		bool getAutoindex() const;
		unsigned int getClientSize() const;
		std::string getIndex() const;
		std::string	getError() const;
		std::map<std::string, std::string> getErrorPath() const;
		std::vector<std::string> getAllowMethods() const;
		std::map<std::string, location> getLocation() const;

		//set
		void setIndex(std::string str);
		void setLocation(std::string str, location loc);
		void setClientSize(unsigned int size);
		void setName(std::string str);
		void setMethod();
		void setRoot(std::string str);

		//exception
		class LoopInReturnLocation : public std::exception
		{
			public:
				const char *what() const throw();
		};
};
