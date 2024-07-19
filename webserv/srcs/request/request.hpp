#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <sys/stat.h>
#include <cstring>

class Request;

#include "../parsing/location.hpp"
#include "../errors/ErrorWebServ.hpp"
#include "../utils/utils.hpp"
#include "Client.hpp"

enum parsingStatus
{
	PARSING_RL,
	PARSING_HEADERS,
	CHECKING_HEADERS,
	PARSING_BODY,
	PARSING_FINISHED,
};

class Request
{
public:
	Request();
	Request(Client *client);
	Request(const Request &other);
	Request &operator=(const Request &other);
	~Request();
	void parseRequest(int fd);
	void printRequest();
	void checkRequest(std::string &currentBuffer);

	// ------------------------------------------- GETTERS

	std::string getMethod();
	std::string getURI();
	std::string getHttpVersion();
	std::string getBody();
	std::map<std::string, std::string> getHeaders();
	std::string getFilePath();
	std::string getFullPath();
	location getCurr_loc();
	std::string getQueryString();
	Client *getClient();
	bool getHasReturn();
	std::string getCurrentFilename();

	// ------------------------------------------- SETTERS

	void setURI(std::string uri);
	void setLocation(location &loc);
	void setFilePath(std::string filePath);
	void setFullPath(std::string fullPath);
	void setQueryString(std::string queryString);
	void setClient(Client *client);
	void setStatus(parsingStatus status);

private:
	// ------------------------------------------ ATTRIBUTES

	std::string _method;
	std::string _uri;
	std::string _httpVersion;
	std::map<std::string, std::string> _headers;
	std::string _body;
	std::string _queryString;
	location _curr_loc;
	std::string _file_path;
	std::string _full_path;

	bool _hasReturn;
	Client *client;

	parsingStatus status;

	std::string _buffer;
	unsigned int _bytesWritten;
	unsigned int _chunkBodySize;
	std::string _chunkBuffer;
	size_t _fileSize;

	std::string _currentBoundary;
	std::string _currentFilename;
	std::string _FullcurrentFilename;
	std::ofstream _currentFile;

	// ------------------------------------------ REQUEST PARSING FUNCTIONS

	std::string parseRequestLine(std::string &current_buffer);
	std::string parseHeaders(std::string &current_buffer);
	void extractQueryString();
	void isMethodAllowed();
	void redirectInURI();
	void parseUri();
	void checkHostName();
	void checkLength();
	void checkFile(int mode);
	bool checkfolder(std::string uri);
	std::string cleanString(std::string toClean);
	void parseBody(std::string &current_buffer);
	void ChunkedBody(std::string &current_buffer);
	void processMultipart(std::string &current_buffer);
	std::string extractFilename(const std::string &contentDisposition);
	std::string extractBoundary(const std::string &contentType);
	void ensureDirectoryExists(const std::string &path);
	void skipHeaders(std::string &current_buffer);
	void processUniqueBody(std::string &current_buffer);
	void processUniqueBodyChunked(std::string &current_buffer);
	std::string generateUniqueFilename(const std::string &baseDir, std::string filename);
	bool fileExists(const std::string &filename);
	std::string filenameByContentType(const std::string &contentType);
	std::string extensionBasedOnContentType(const std::string &contentType);
	std::map<std::string, std::string> initMimeTypeToExtension();
	std::map<std::string, std::string> initMimeTypeToFilename();

	// ------------------------------------------ ERROR

	class bodySize : public ErrorWebServ
	{
	public:
		bodySize(int errorCode) : ErrorWebServ(errorCode) {}
		const char *what() const throw();
	};
	class wrongRLInput : public ErrorWebServ
	{
	public:
		wrongRLInput(int errorCode) : ErrorWebServ(errorCode) {}
		const char *what() const throw();
	};

	class headerParsingError : public ErrorWebServ
	{
	public:
		headerParsingError(int errorCode) : ErrorWebServ(errorCode) {}
		const char *what() const throw();
	};
	class invalidContentLength : public ErrorWebServ
	{
	public:
		invalidContentLength(int errorCode) : ErrorWebServ(errorCode) {}
		const char *what() const throw();
	};
	class shorterBodyContent : public ErrorWebServ
	{
	public:
		shorterBodyContent(int errorCode) : ErrorWebServ(errorCode) {}
		const char *what() const throw();
	};

	class longerBodyContent : public ErrorWebServ
	{
	public:
		longerBodyContent(int errorCode) : ErrorWebServ(errorCode) {}
		const char *what() const throw();
	};
	class contentLengthUnspecified : public ErrorWebServ
	{
	public:
		contentLengthUnspecified(int errorCode) : ErrorWebServ(errorCode) {}
		const char *what() const throw();
	};
	class unauthorizedMethod : public ErrorWebServ
	{
	public:
		unauthorizedMethod(int errorCode) : ErrorWebServ(errorCode) {}
		const char *what() const throw();
	};
	class fileNotFound : public ErrorWebServ
	{
	public:
		fileNotFound(int errorCode) : ErrorWebServ(errorCode) {}
		const char *what() const throw();
	};
	class unsupportedHTTPVersion : public ErrorWebServ
	{
	public:
		unsupportedHTTPVersion(int errorCode) : ErrorWebServ(errorCode) {}
		const char *what() const throw();
	};
	class chunkSizeError : public ErrorWebServ
	{
	public:
		chunkSizeError(int errorCode) : ErrorWebServ(errorCode) {}
		const char *what() const throw();
	};
	class chunkDataError : public ErrorWebServ
	{
	public:
		chunkDataError(int errorCode) : ErrorWebServ(errorCode) {}
		const char *what() const throw();
	};

	class cantOpenFile : public ErrorWebServ
	{
	public:
		cantOpenFile(int errorCode) : ErrorWebServ(errorCode) {}
		const char *what() const throw();
	};
};

