#include "../include/webserv.hpp"

int main(int argc, char **argv)
{
	Web web;

	if (argc < 2)
	{
		std::cerr << "Error: Wrong number of arguments" << std::endl;
		return 1;
	}
	try
	{
		signal(SIGPIPE, SIG_IGN);
		web.parsing(argv, argc);	
		web.run();		
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}

void Web::check()
{
	for (unsigned int i = 0; i < _serv.size(); i++)
	{
		if (_serv[i].getListen().empty())
			throw ExceptionInFile();
		if (_serv[i].getHost().empty())
			throw ExceptionInFile();
		if (_serv[i].getName().empty())
			_serv[i].setName("localhost");
		if (_serv[i].getRoot().empty())
			throw ExceptionInFile();
		if (_serv[i].getClientSize() == 0)
			_serv[i].setClientSize(CLIENT_SIZE);
		if (_serv[i].getAllowMethods().empty())
			_serv[i].setMethod();
		if (_serv[i].getRoot().substr(_serv[i].getRoot().size()-1).compare("/"))
			_serv[i].setRoot("/");

		location a = _serv[i].getLocation()["/"];
		if (_serv[i].getIndex().empty() && !_serv[i].getLocation().at("/").getIndex().empty())
			_serv[i].setIndex(_serv[i].getLocation().at("/").getIndex());
		else if (!_serv[i].getIndex().empty() && _serv[i].getLocation().at("/").getIndex().empty())
		{
			a.setIndex(_serv[i].getIndex());
			_serv[i].setLocation("/", a);
		}
		else
			throw ExceptionInFile();
		_serv[i].checkReturn();
	}
}
void Web::parsing(char **argv, int argc)
{
	std::ifstream file;
	std::vector<std::string> word;
	std::vector< std::vector<std::string> > fileline;
	std::string line;
	unsigned int i = 0;
	for (int j = 1; j < argc; j++)
	{
		file.open(argv[j]);
		if (!file)
			throw ExceptionErrorFile();
		for (; getline(file, line); i++)
		{
			if (!line.empty())
			{
				std::stringstream ss(line);
				for (; ss;)
				{
					std::string w;
					ss >> w;
					if (!w.empty())
					{
						if (w.substr(w.size() - 1).compare(";") == 0)
							w = w.substr(0, w.size() - 1);
						word.push_back(w);
					}
				}
				fileline.push_back(word);
				word.clear();
			}
		}
		file.close();
		;
		i = 0;
		for (; i < fileline.size(); i++)
		{
			if (fileline[i][0].compare("server"))
				throw std::exception();
			else
			{
				if (fileline[i][0].compare("{") == 0)
					throw std::exception();
				configserv server;
				server.serv(fileline, ++i);
				this->_serv.push_back(server);
			}
		}
		fileline.clear();
	}
	check();
}

void Web::run() const
{
	Server server = Server(this->_serv);
	server.set_server();
	server.run_server();
}

const char *Web::ExceptionErrorFile::what() const throw()
{
	return "could not open file.";
}

const char *Web::ExceptionInFile::what() const throw()
{
	return "bad input in file.";
}
