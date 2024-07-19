#pragma once
#include "../response/response.hpp"
#include "../request/request.hpp"
#include "../errors/ErrorWebServ.hpp"
#define MAX_BATCH 5000

class Handler
{
public:
	Handler(Request &request, Response &response);
	~Handler();

	void process();
	void setRequest(Request &req);
	Request getRequest();

private:
	// ----------------------------------------- ATTRIBUTES //
	Request &_request;
	Response &_response;
	std::map<std::string, void (Handler::*)()> _methodFunctions;

	// ----------------------------------------- FUNCTIONS //

	void handleGet();
	void handlePost();
	void handleDelete();

	std::map<std::string, std::string> initializeMIMEMap();
	ssize_t getFileSize(const std::string &filename);
	// ------------------------------------------ ERRORS //

	class couldNotOpenFile : public ErrorWebServ
	{
	public:
		couldNotOpenFile(int errorCode) : ErrorWebServ(errorCode) {}
		const char *what() const throw();
	};

	class unknownMethod : public ErrorWebServ
	{
	public:
		unknownMethod(int errorCode) : ErrorWebServ(errorCode) {}
		const char *what() const throw();
	};

	class deletionFailed : public ErrorWebServ
	{
	public:
		deletionFailed(int errorCode) : ErrorWebServ(errorCode) {}
		const char *what() const throw();
	};

	class postFailed : public ErrorWebServ
	{
	public:
		postFailed(int errorCode) : ErrorWebServ(errorCode) {}
		const char *what() const throw();
	};
	class unsupportedMediaType : public ErrorWebServ
	{
	public:
		unsupportedMediaType(int errorCode) : ErrorWebServ(errorCode) {}
		const char *what() const throw();
	};
};