#include "Handler.hpp"

Handler::Handler(Request &request, Response &response) : _request(request), _response(response)

{
	_methodFunctions["GET"] = &Handler::handleGet;
	_methodFunctions["POST"] = &Handler::handlePost;
	_methodFunctions["DELETE"] = &Handler::handleDelete;
}

Handler::~Handler()
{
	// Destructor implementation
}

// ------------------------------------------------------ FUNCTIONS //

// * Starts the request handling process by invoking the appropriate method based on the HTTP request method.
// * Looks up the method in a map and calls the corresponding member function if found.

void Handler::process()
{
	// std::cout << "Current METHOD is " << _request.getMethod() << std::endl;
	// Find the request method in the map of method functions
	std::map<std::string, void (Handler::*)()>::iterator it = _methodFunctions.find(_request.getMethod());
	if (it != _methodFunctions.end()) // If method is found, call the corresponding function
		(this->*(it->second))();
	else
		throw unknownMethod(501);
}

// * Handles HTTP POST requests by processing form data or file uploads.
// * For "application/x-www-form-urlencoded" content type, it saves the form data to a file.
// * For "multipart/form-data" content type, it processes each file part and saves it.

void Handler::handlePost()
{
	_response.setStatusCode(201);
	_response.setContentType("text/plain");
	_response.setBody("POST successful.");
	_request.getClient()->setFlag(RESPONSE_OK);
}

std::map<std::string, std::string> Handler::initializeMIMEMap()
{
	std::map<std::string, std::string> extensionToMIME;
	// Audio types
	extensionToMIME["aac"] = "audio/aac";
	extensionToMIME["mp3"] = "audio/mpeg";
	extensionToMIME["oga"] = "audio/ogg";
	extensionToMIME["opus"] = "audio/opus";
	extensionToMIME["wav"] = "audio/wav";
	extensionToMIME["weba"] = "audio/webm";
	extensionToMIME["mid"] = "audio/midi";
	extensionToMIME["midi"] = "audio/midi";
	// Video types
	extensionToMIME["mp4"] = "video/mp4";
	extensionToMIME["mpeg"] = "video/mpeg";
	extensionToMIME["ogv"] = "video/ogg";
	extensionToMIME["webm"] = "video/webm";
	extensionToMIME["avi"] = "video/x-msvideo";
	extensionToMIME["3gp"] = "video/3gpp";
	extensionToMIME["3g2"] = "video/3gpp2";
	// Image types
	extensionToMIME["apng"] = "image/apng";
	extensionToMIME["avif"] = "image/avif";
	extensionToMIME["bmp"] = "image/bmp";
	extensionToMIME["gif"] = "image/gif";
	extensionToMIME["jpeg"] = "image/jpeg";
	extensionToMIME["jpg"] = "image/jpeg";
	extensionToMIME["png"] = "image/png";
	extensionToMIME["svg"] = "image/svg+xml";
	extensionToMIME["tif"] = "image/tiff";
	extensionToMIME["tiff"] = "image/tiff";
	extensionToMIME["webp"] = "image/webp";
	extensionToMIME["ico"] = "image/x-icon";
	// Text types
	extensionToMIME["css"] = "text/css";
	extensionToMIME["csv"] = "text/csv";
	extensionToMIME["html"] = "text/html";
	extensionToMIME["htm"] = "text/html";
	extensionToMIME["js"] = "application/javascript";
	extensionToMIME["json"] = "application/json";
	extensionToMIME["jsonld"] = "application/ld+json";
	extensionToMIME["txt"] = "text/plain";
	extensionToMIME["xhtml"] = "application/xhtml+xml";
	extensionToMIME["xml"] = "application/xml";
	// Application types
	extensionToMIME["pdf"] = "application/pdf";
	extensionToMIME["zip"] = "application/zip";
	extensionToMIME["7z"] = "application/x-7z-compressed";
	extensionToMIME["rar"] = "application/vnd.rar";
	extensionToMIME["tar"] = "application/x-tar";
	extensionToMIME["gz"] = "application/gzip";
	extensionToMIME["bz"] = "application/x-bzip";
	extensionToMIME["bz2"] = "application/x-bzip2";
	extensionToMIME["doc"] = "application/msword";
	extensionToMIME["docx"] = "application/vnd.openxmlformats-officedocument.wordprocessingml.document";
	extensionToMIME["ppt"] = "application/vnd.ms-powerpoint";
	extensionToMIME["pptx"] = "application/vnd.openxmlformats-officedocument.presentationml.presentation";
	extensionToMIME["xls"] = "application/vnd.ms-excel";
	extensionToMIME["xlsx"] = "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
	extensionToMIME["epub"] = "application/epub+zip";
	extensionToMIME["jar"] = "application/java-archive";
	extensionToMIME["rtf"] = "application/rtf";
	extensionToMIME["sh"] = "application/x-sh";
	extensionToMIME["vsd"] = "application/vnd.visio";
	extensionToMIME["csh"] = "application/x-csh";
	extensionToMIME["php"] = "application/x-httpd-php";
	extensionToMIME["xul"] = "application/vnd.mozilla.xul+xml";
	extensionToMIME["ods"] = "application/vnd.oasis.opendocument.spreadsheet";
	extensionToMIME["odp"] = "application/vnd.oasis.opendocument.presentation";
	extensionToMIME["odt"] = "application/vnd.oasis.opendocument.text";
	extensionToMIME["mjs"] = "text/javascript";

	return extensionToMIME;
}

ssize_t Handler::getFileSize(const std::string &filename)
{
	std::ifstream file(filename.c_str(), std::ios::binary | std::ios::ate);
	return file.tellg();
}

// * This function handles a GET request by determining the file extension of the requested file,
// * setting the appropriate content type in the response, loading the file content into the response,

void Handler::handleGet()
{
	std::string filePath = _request.getFilePath();							 // Get the file path from the request object.
	std::string extension = filePath.substr(filePath.find_last_of('.') + 1); // Extract the file extension.
	const static std::map<std::string, std::string> extensionToMIME = initializeMIMEMap();
	std::map<std::string, std::string>::const_iterator it = extensionToMIME.find(extension);

	if (it != extensionToMIME.end())
		_response.setContentType(it->second);
	else
		_response.setContentType("application/octet-stream"); // Default MIME type

	ssize_t fileSize = getFileSize(_request.getFullPath());
	if (fileSize < BUFFER_SIZE)
	{
		_response.loadContent(_request.getFullPath());
		_response.setStatusCode(200);
		_request.getClient()->setFlag(RESPONSE_OK);
	}
	else
	{
		int fd = open(_request.getFullPath().c_str(), O_RDONLY);
		if (fd == -1)
			throw couldNotOpenFile(404);
		_response.setFD(fd);
		_response.setFileSize(fileSize);
		_response.setStatusCode(202); // Processing body
		_response.formatResponseWithoutBody(*_request.getClient(), _request);
		_request.getClient()->setFlag(WRITING_RESPONSE);
	}
}

// * This function handles a DELETE request

void Handler::handleDelete()
{
	std::string filePath = _request.getFullPath();
	if (std::remove(filePath.c_str()) != 0)
		throw deletionFailed(500);
	_response.setStatusCode(204);
	_response.setContentType("text/plain");
	_response.setBody("DELETE successful.");
	_request.getClient()->setFlag(RESPONSE_OK);
}
Request Handler::getRequest()
{
	return (_request);
}
void Handler::setRequest(Request &req)
{
	_request = req;
}

// ------------------------------------------------------ ERRORS //

const char *Handler::couldNotOpenFile::what() const throw()
{
	return ("Error while trying to open file (Handler)");
}

const char *Handler::unknownMethod::what() const throw()
{
	return ("Unhandled method.");
}
const char *Handler::deletionFailed::what() const throw()
{
	return ("DELETE failed.");
}

const char *Handler::postFailed::what() const throw()
{
	return ("POST processing failed.");
}

const char *Handler::unsupportedMediaType::what() const throw()
{
	return ("Unsupported media type during POST.");
}
