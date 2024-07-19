#include "CgiHandler.hpp"

CgiHandler::CgiHandler(Request &request)
{
	if (request.getMethod().compare("POST") == 0)
	{
		std::string filename = "Page/data/" + request.getCurrentFilename();
		std::ifstream file(filename.c_str());
		if (!file)
		{
			// std::cerr << "Unable to open file " << filename;
			throw InternalServerError(500);
		}
		std::string line;
		while (std::getline(file, line))
			_body += line + "\n";
		file.close();
	}
	initenv(request);
}

CgiHandler::~CgiHandler()
{
}

void CgiHandler::initenv(Request &request)
{
	std::stringstream ss;
	_env["AUTH_TYPE"] = request.getHeaders().count("Authorization") ? request.getHeaders()["Authorization"] : "";
	ss << _body.size();
	_env["CONTENT_LENGTH"] = ss.str();
	ss.str("");
	_env["CONTENT_TYPE"] = request.getHeaders().count("Content-Type") ? request.getHeaders()["Content-Type"] : "";
	_env["GATEWAY_INTERFACE"] = "CGI/1.1";
	_env["PATH_INFO"] = request.getFullPath();
	_env["PATH_TRANSLATED"] = request.getFullPath();
	_env["QUERY_STRING"] = request.getQueryString();
	_env["REMOTE_ADDR"] = request.getClient()->get_listen_socket().get_host();
	_env["REMOTE_IDENT"] = request.getHeaders().count("Authorization") ? request.getHeaders()["Authorization"] : "";
	_env["REMOTE_USER"] = request.getHeaders().count("Authorization") ? request.getHeaders()["Authorization"] : "";
	_env["REQUEST_METHOD"] = request.getMethod();
	_env["REQUEST_URI"] = request.getFullPath() + (request.getQueryString().empty() ? "" : "?" + request.getQueryString());
	_env["SCRIPT_NAME"] = request.getFullPath();
	_env["SERVER_NAME"] = request.getClient()->get_listen_socket().get_name();
	ss << request.getClient()->get_listen_socket().get_port();
	_env["SERVER_PORT"] = ss.str();
	_env["SERVER_PROTOCOL"] = "HTTP/1.1";
	_env["SERVER_SOFTWARE"] = "Weebserv/1.0";
	_env["REDIRECT_STATUS"] = "200";
}

char **CgiHandler::EnvToArray() const
{
	char **array = new char *[_env.size() + 1];
	int j = 0;
	for (std::map<std::string, std::string>::const_iterator i = _env.begin(); i != _env.end(); i++)
	{
		std::string line = i->first + "=" + i->second;
		array[j] = new char[line.size() + 1];
		strcpy(array[j], line.c_str());
		j++;
	}
	array[j] = NULL;

	return array;
}

std::string CgiHandler::execute(std::string Script, Response &resp)
{
	char **env = EnvToArray();
	pid_t pid;
	std::string newbody;
	int fdin = dup(STDIN_FILENO);
	int fdout = dup(STDOUT_FILENO);

	FILE *fIn = tmpfile();
	FILE *fOut = tmpfile();
	long fdIn = fileno(fIn);
	long fdOut = fileno(fOut);
	int ret = 1;

	write(fdIn, _body.c_str(), _body.size());
	lseek(fdIn, 0, SEEK_SET);

	pid = fork();
	if (pid == -1)
	{
		// std::cerr << "Error Fork";
		throw InternalServerError(500);
	}
	else if (!pid)
	{
		char *argv[2];
		argv[0] = const_cast<char *>(Script.c_str());
		argv[1] = NULL;
		dup2(fdIn, STDIN_FILENO);
		dup2(fdOut, STDOUT_FILENO);
		execve(Script.c_str(), argv, env);
		std::cerr << "Execution failed" << std::endl;
		write(STDOUT_FILENO, "Code 500\n", 10);
		exit(1);
	}
	else
	{
		char buffer[BUFFER];
		waitpid(-1, NULL, 0);
		lseek(fdOut, 0, SEEK_SET);
		ret = 1;
		while (ret > 0)
		{
			memset(buffer, 0, BUFFER);
			ret = read(fdOut, buffer, BUFFER - 1);
			newbody += buffer;
		}
	}

	dup2(fdin, STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	fclose(fIn);
	fclose(fOut);
	close(fdIn);
	close(fdOut);
	close(fdin);
	close(fdout);

	for (unsigned int i = 0; env[i]; i++)
		delete[] env[i];
	delete[] env;

	if (newbody.compare("Code 500\n") == 0)
		throw InternalServerError(500);

	size_t pos = newbody.find("\n\n");
	if (pos != std::string::npos)
	{
		std::string headers_str = newbody.substr(0, pos);
		std::string body = newbody.substr(pos);
		std::istringstream stream(headers_str);
		std::string line;

		while (std::getline(stream, line))
		{
			size_t delimiter_pos = line.find(": ");
			if (delimiter_pos != std::string::npos)
			{
				std::string key = line.substr(0, delimiter_pos);
				std::string value = line.substr(delimiter_pos + 2);
				if (key == "Content-Type")
					resp.setContentType(value);
			}
		}
		newbody = body;
	}
	return newbody;
}

const char *CgiHandler::InternalServerError::what() const throw()
{
	return "Internal Server Error";
}