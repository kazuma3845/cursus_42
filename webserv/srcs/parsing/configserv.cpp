# include "configserv.hpp"
#include "../../include/webserv.hpp"

configserv::configserv()
{
	_autoindex = false;
	_client_size = 0;
}

void configserv::serv(std::vector< std::vector<std::string> > file, unsigned int &i)
{
	std::string tab[9] = {"listen", "server_name", "host", "root", "autoindex", "client_max_body_size", "index", "error_page", "allow_methods"};
	for (; i < file.size(); i++)
	{
		if (file[i][0].compare("}") == 0)
			return ;
		if (file[i][0].compare("#") == 0)
			;
		else if (file[i][0].compare("location") == 0)
		{
			location a;
			int r = i;
			a.init(file, i);
			_location[file[r][1]] = a;
		}
		else
		{
			int j = 0;
			for (;j < 9 && tab[j].compare(file[i][0]); j++)
				;
			switch(j)
			{
				case 0:
				{
					size_t found = file[i][1].find(":");
					if (found != std::string::npos)
					{
						_host = file[i][1].substr(0, found);
						file[i][1] = file[i][1].substr(found + 1, file[i][1].size());
					}
					std::string str = file[i][1];
					std::stringstream ss(str);
					int x;
					ss >> x;
					_listen.push_back(x);
					break ;
				}
				case 1:
				{
					if (_name.empty())
						_name = file[i][1];
					else
						throw Web::ExceptionInFile();
					break ;
				}
				case 2:
				{
					if (_host.empty())
						_host = file[i][1];
					else
						throw Web::ExceptionInFile();
					break ;
				}
				case 3:
				{
					if (_root.empty())
						_root = file[i][1];
					else
						throw Web::ExceptionInFile();
					break ;
				}
				case 4:
				{
					if (file[i][1].compare("on") == 0)
						_autoindex = true;
					break ;
				}
				case 5:
				{
					if (_client_size != 0)
						throw Web::ExceptionInFile();
					std::string str = file[i][1];
					std::stringstream ss(str);
					int x;
					ss >> x;
					_client_size = x;
					break ;
				}
				case 6:
				{
					if (_index.empty())
						_index = file[i][1];
					else
						throw Web::ExceptionInFile();
					break ;
				}
				case 7:
				{
					_error = file[i][1];
					_errorpath[_error] = file[i][2];
					break ;
				}
				case 8:
				{
					for (unsigned int k = 1; k < file[i].size(); k++)
						_allow_methods.push_back(file[i][k]);
					break ;
				}
				default:
				{
					throw Web::ExceptionInFile();
					break ;
				}
			}
		}
	}
}

void configserv::checkReturn(void)
{
	location curr_loc;
	for (std::map<std::string, location>::iterator it = _location.begin(); it != _location.end(); ++it)
	{
		curr_loc = it->second;
		while (true)
		{
			if (!curr_loc.getReturn().empty())
			{
				if (it->second.getVisitedLoc().count(curr_loc.getName()))
				{
					throw LoopInReturnLocation();
					exit(1);
				}
				if (_location.count(curr_loc.getName()) && !_location[curr_loc.getReturn()].empty())
				{
					it->second.setVisitedLoc(curr_loc.getName(), curr_loc);
					curr_loc = _location[curr_loc.getReturn()];
				}
				else
					break ;
			}
			else
				break;
		}
	}
}

std::vector<int> configserv::getListen() const
{
	return _listen;
}

std::string configserv::getName() const
{
	return _name;
}

std::string configserv::getHost() const
{
	return _host;
}

std::string configserv::getRoot() const
{
	return _root;
}

bool configserv::getAutoindex() const
{
	return _autoindex;
}

unsigned int configserv::getClientSize() const
{
	return _client_size;
}

std::string configserv::getIndex() const
{
	return _index;
}

std::string	configserv::getError() const
{
	return _error;
}

std::map<std::string, std::string> configserv::getErrorPath() const
{
	return _errorpath;
}

std::vector<std::string> configserv::getAllowMethods() const
{
	return _allow_methods;
}

std::map<std::string, location> configserv::getLocation() const
{
	return _location;
}

void configserv::setClientSize(unsigned int size)
{
	_client_size = size;
}

void configserv::setName(std::string str)
{
	_name = str;
}

void configserv::setMethod()
{
	_allow_methods.push_back("GET");
	_allow_methods.push_back("HEAD");
}

void configserv::setIndex(std::string str)
{
	_index = str;
}

void configserv::setLocation(std::string str, location loc)
{
	_location[str] = loc;
}

void configserv::setRoot(std::string str)
{
	_root += str;
}

const char *configserv::LoopInReturnLocation::what() const throw()
{
	return "Infinite loop in return location.";
}
