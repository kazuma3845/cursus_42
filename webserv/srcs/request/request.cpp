#include "request.hpp"

// ------------------------------------ COPLIEN -- //

Request::Request()
{
	// std::cout << "Request instance created." << std::endl;
}

Request::Request(Client *client) : _hasReturn(false), client(client)
{
	status = PARSING_RL;
	_chunkBodySize = 0;
	_bytesWritten = 0;
	_currentFilename = "";
	_fileSize = 0;
	// std::cout << "Request instance with pointer on client created : " << this->client->get_fd() << std::endl;
}

Request::Request(const Request &other)
{
	*this = other;
}

Request &Request::operator=(const Request &other)
{
	if (this != &other)
	{
		_method = other._method;
		_uri = other._uri;
		_httpVersion = other._httpVersion;
		_headers = other._headers;
		_body = other._body;
		_queryString = other._queryString;
		_curr_loc = other._curr_loc;
		_file_path = other._file_path;
		_full_path = other._full_path;
		_hasReturn = other._hasReturn;
		status = other.status;
		_buffer = other._buffer;
		_chunkBodySize = other._chunkBodySize;
		_chunkBuffer = other._chunkBuffer;
		_bytesWritten = other._bytesWritten;
		_fileSize = other._fileSize;
		_currentFilename = other._currentFilename;
	}
	return *this;
}

Request::~Request()
{
	// std::cout << "Request instance destroyed ..." << std::endl;
}
// ---------------------------------- GETTERS -- //

std::string Request::getMethod()
{
	return (_method);
}

std::string Request::getURI()
{
	return (_uri);
}

std::string Request::getHttpVersion()
{
	return (_httpVersion);
}

std::string Request::getBody()
{
	return (_body);
}

std::map<std::string, std::string> Request::getHeaders()
{
	return (_headers);
}

location Request::getCurr_loc()
{
	return _curr_loc;
}

std::string Request::getFilePath()
{
	return (_file_path);
}

std::string Request::getFullPath()
{
	return (_full_path);
}

std::string Request::getQueryString()
{
	return (_queryString);
}
Client *Request::getClient()
{
	return client;
}

bool Request::getHasReturn()
{
	return _hasReturn;
}

std::string Request::getCurrentFilename()
{
	return _FullcurrentFilename;
}

// ---------------------------------- SETTERS -- //

void Request::setURI(std::string uri)
{
	_uri = uri;
}
void Request::setLocation(location &loc)
{
	_curr_loc = loc;
}

void Request::setFilePath(std::string filePath)
{
	_file_path = filePath;
}

void Request::setFullPath(std::string fullPath)
{
	_full_path = fullPath;
}

void Request::setQueryString(std::string queryString)
{
	_queryString = queryString;
}

void Request::setClient(Client *client)
{
	this->client = client;
}

void Request::setStatus(parsingStatus status)
{
	this->status = status;
}

// ---------------------------------- OTHER FUNCTIONS -- //

// * This function prints out the parsed contents of an HTTP request, including method, URI, headers, body, and other details.

void Request::printRequest()
{
	std::cout << " -- REQUEST PARSED -- " << std::endl;
	std::cout << std::endl
			  << "Method : " << _method << std::endl;
	std::cout << "URI : " << _uri << std::endl;
	std::cout << "Version : " << _httpVersion << std::endl;

	// Iterate through headers and print each key-value pair
	for (std::map<std::string, std::string>::iterator it = _headers.begin(); it != _headers.end(); ++it)
		std::cout << it->first << " : " << it->second << std::endl;

	// Print body or indicate if it's empty
	if (!_body.empty())
		std::cout << "Body : " << _body << std::endl;
	else
		std::cout << "! Body is EMPTY" << std::endl;

	// Print location or indicate if it's empty
	if (!_curr_loc.empty())
		std::cout << "Location : " << _curr_loc.getName() << std::endl;
	else
		std::cout << "! Location is EMPTY" << std::endl;

	std::cout << "File_path : " << _file_path << std::endl;
	std::cout << "Full_path : " << _full_path << std::endl;

	// Print query string or indicate if none found
	if (!_queryString.empty())
		std::cout << "Query String : " << _queryString << std::endl;
	else
		std::cout << "! No query string found." << std::endl;

	std::cout << std::endl;
	std::cout << " -- END OF PARSED REQUEST -- " << std::endl;
}

void Request::extractQueryString()
{
	size_t pos = _uri.find('?');

	std::string tmp = _uri.substr(0, pos);
	_queryString = _uri.substr(pos + 1);

	_uri = tmp;
}

// * This function checks various aspects of an HTTP request to ensure it meets certain criteria.
// * It parses the URI, checks if the method is allowed, handles redirections, checks file existence,

void Request::checkRequest(std::string &currentBuffer)
{
	parseUri(); // Parses the URI to get the location of the requested resource.

	isMethodAllowed(); // Checks if the HTTP method used in the request is allowed for the resource.

	redirectInURI(); // Checks if there is a redirection specified for the URI.

	checkFile(F_OK); // Checks if the requested file exists and can be accessed.

	checkHostName();

	checkLength();

	// Sets up the connection mode in the Client object to keep-alive if the "Connection" header is set to "keep-alive".
	if (_headers["Connection"] == "keep-alive")
		client->setKeepAlive(true);

	if (_headers.count("Expect")) // Si on a trouvé la fin et qu'il y a un expect, on va stocker le reste dans le buffer et actualiser les status
	{
		client->setFlag(EXPECTING);
		client->setResp("HTTP/1.1 100 Continue\r\n\r\n");
		return;
	}

	if (currentBuffer.empty() && !_headers.count("Content-Type")) // on check si il y a quelque chose derriere (du body)
	{
		status = PARSING_FINISHED;
		client->setFlag(PREPARING_RESPONSE);
	}
	else
		status = PARSING_BODY;
}

void Request::ChunkedBody(std::string &current_buffer)
{
	size_t pos = 0;
	std::string chunkSizeLine;
	size_t chunkSize = 0;

	// std::cout << " -------  Coming into CHUNKING parsing  ---------" << std::endl;
	// Ajouter le buffer courant au buffer de chunk temporaire pour traitement
	_chunkBuffer += current_buffer;
	current_buffer.clear();

	while (true)
	{
		if (_chunkBodySize == 0)
		{
			pos = _chunkBuffer.find("\r\n");
			if (pos == std::string::npos)
			{
				// Si on ne trouve pas de fin de ligne, on a besoin de plus de données
				return;
			}
			// Extraire la ligne de taille de chunk
			chunkSizeLine = _chunkBuffer.substr(0, pos);
			_chunkBuffer.erase(0, pos + 2); // Supprimer la taille du chunk et le \r\n du buffer de chunk

			std::stringstream ss(chunkSizeLine);
			ss >> std::hex >> chunkSize;
			std::cout << "Chunksize is : " << chunkSize << std::endl;
			std::cout << "_fileSize is : " << _fileSize << std::endl;

			_fileSize += chunkSize;
			std::cout << _fileSize << std::endl;
			if (_fileSize > client->get_listen_socket().get_clientSize())
				throw bodySize(413);
			if (chunkSize == 0)
			{
				status = PARSING_FINISHED;
				client->setFlag(CHECKING_REQUEST);
				_currentFile.close();
				_currentFilename.clear();
				_bytesWritten = 0;
				_fileSize = 0;
				return;
			}
			_chunkBodySize = chunkSize;
		}

		if (_chunkBuffer.size() >= _chunkBodySize + 2)
		{ // +2 pour inclure le \r\n final du chunk
			std::string chunkData = _chunkBuffer.substr(0, _chunkBodySize);
			_chunkBuffer.erase(0, _chunkBodySize + 2); // Enlever le chunk et le \r\n
			if (_headers["Content-Type"].find("multipart/form-data") != std::string::npos)
				processMultipart(chunkData);
			else
				processUniqueBodyChunked(chunkData);
			_chunkBodySize = 0;
		}
		else
			return;
	}
}

void Request::skipHeaders(std::string &current_buffer)
{
	size_t pos = current_buffer.find("\r\n\r\n");
	current_buffer = current_buffer.substr(pos + 4);
}

bool Request::fileExists(const std::string &filename)
{
	struct stat buffer;
	return (stat(filename.c_str(), &buffer) == 0);
}

std::string Request::generateUniqueFilename(const std::string &baseDir, std::string filename)
{
	int counter = 1;
	std::string newFilename;
	std::string fileExtension;

	size_t extPos = filename.find_last_of('.');
	if (extPos != std::string::npos)
	{
		fileExtension = filename.substr(extPos);
		filename.erase(extPos);
	}

	std::ostringstream oss;
	do
	{
		oss.str(""); // Nettoyer le flux
		oss << filename << counter << fileExtension;
		newFilename = oss.str();
		counter++;
	} while (fileExists(baseDir + newFilename));

	return newFilename;
}
std::map<std::string, std::string> Request::initMimeTypeToExtension()
{
	std::map<std::string, std::string> mimeTypeToExtension;
	// Audio/Video files
	mimeTypeToExtension["audio/aac"] = ".aac";
	mimeTypeToExtension["video/mp4"] = ".mp4";
	mimeTypeToExtension["audio/midi"] = ".midi";
	mimeTypeToExtension["audio/mpeg"] = ".mp3";
	mimeTypeToExtension["video/mpeg"] = ".mpeg";
	mimeTypeToExtension["audio/ogg"] = ".oga";
	mimeTypeToExtension["video/ogg"] = ".ogv";
	mimeTypeToExtension["audio/opus"] = ".opus";
	mimeTypeToExtension["audio/wav"] = ".wav";
	mimeTypeToExtension["audio/webm"] = ".weba";
	mimeTypeToExtension["video/webm"] = ".webm";
	// Image files
	mimeTypeToExtension["image/apng"] = ".apng";
	mimeTypeToExtension["image/avif"] = ".avif";
	mimeTypeToExtension["image/bmp"] = ".bmp";
	mimeTypeToExtension["image/gif"] = ".gif";
	mimeTypeToExtension["image/jpeg"] = ".jpeg";
	mimeTypeToExtension["image/png"] = ".png";
	mimeTypeToExtension["image/svg+xml"] = ".svg";
	mimeTypeToExtension["image/tiff"] = ".tiff";
	mimeTypeToExtension["image/webp"] = ".webp";
	// Text files
	mimeTypeToExtension["text/css"] = ".css";
	mimeTypeToExtension["text/csv"] = ".csv";
	mimeTypeToExtension["text/html"] = ".html";
	mimeTypeToExtension["text/javascript"] = ".js";
	mimeTypeToExtension["text/plain"] = ".txt";
	mimeTypeToExtension["application/json"] = ".json";
	// Application files
	mimeTypeToExtension["application/java-archive"] = ".jar";
	mimeTypeToExtension["application/msword"] = ".doc";
	mimeTypeToExtension["application/pdf"] = ".pdf";
	mimeTypeToExtension["application/rtf"] = ".rtf";
	mimeTypeToExtension["application/vnd.ms-excel"] = ".xls";
	mimeTypeToExtension["application/vnd.ms-powerpoint"] = ".ppt";
	mimeTypeToExtension["application/vnd.oasis.opendocument.presentation"] = ".odp";
	mimeTypeToExtension["application/vnd.oasis.opendocument.spreadsheet"] = ".ods";
	mimeTypeToExtension["application/vnd.oasis.opendocument.text"] = ".odt";
	mimeTypeToExtension["application/x-7z-compressed"] = ".7z";
	mimeTypeToExtension["application/x-bzip"] = ".bz";
	mimeTypeToExtension["application/x-bzip2"] = ".bz2";
	mimeTypeToExtension["application/x-rar-compressed"] = ".rar";
	mimeTypeToExtension["application/zip"] = ".zip";
	mimeTypeToExtension["application/x-tar"] = ".tar";
	return mimeTypeToExtension;
}

std::map<std::string, std::string> Request::initMimeTypeToFilename()
{
	std::map<std::string, std::string> mimeTypeToFilename;
	// Audio files
	mimeTypeToFilename["audio/aac"] = "audio_track.aac";
	mimeTypeToFilename["audio/midi"] = "music.midi";
	mimeTypeToFilename["audio/mpeg"] = "sound.mp3";
	mimeTypeToFilename["audio/ogg"] = "audio.ogg";
	mimeTypeToFilename["audio/opus"] = "audio.opus";
	mimeTypeToFilename["audio/wav"] = "audio.wav";
	mimeTypeToFilename["audio/webm"] = "audio.webm";
	// Video files
	mimeTypeToFilename["video/mp4"] = "video.mp4";
	mimeTypeToFilename["video/mpeg"] = "video.mpeg";
	mimeTypeToFilename["video/ogg"] = "video.ogv";
	mimeTypeToFilename["video/webm"] = "video.webm";
	mimeTypeToFilename["video/3gpp"] = "video.3gp";
	mimeTypeToFilename["video/3gpp2"] = "video.3g2";
	// Image files
	mimeTypeToFilename["image/apng"] = "image.apng";
	mimeTypeToFilename["image/avif"] = "image.avif";
	mimeTypeToFilename["image/bmp"] = "image.bmp";
	mimeTypeToFilename["image/gif"] = "image.gif";
	mimeTypeToFilename["image/jpeg"] = "image.jpeg";
	mimeTypeToFilename["image/png"] = "image.png";
	mimeTypeToFilename["image/svg+xml"] = "image.svg";
	mimeTypeToFilename["image/tiff"] = "image.tiff";
	mimeTypeToFilename["image/webp"] = "image.webp";
	// Text files
	mimeTypeToFilename["text/css"] = "stylesheet.css";
	mimeTypeToFilename["text/csv"] = "data.csv";
	mimeTypeToFilename["text/html"] = "document.html";
	mimeTypeToFilename["text/javascript"] = "script.js";
	mimeTypeToFilename["text/plain"] = "text.txt";
	// Application-specific files
	mimeTypeToFilename["application/java-archive"] = "application.jar";
	mimeTypeToFilename["application/msword"] = "document.doc";
	mimeTypeToFilename["application/pdf"] = "document.pdf";
	mimeTypeToFilename["application/rtf"] = "document.rtf";
	mimeTypeToFilename["application/vnd.ms-excel"] = "spreadsheet.xls";
	mimeTypeToFilename["application/vnd.ms-powerpoint"] = "presentation.ppt";
	mimeTypeToFilename["application/vnd.oasis.opendocument.presentation"] = "presentation.odp";
	mimeTypeToFilename["application/vnd.oasis.opendocument.spreadsheet"] = "spreadsheet.ods";
	mimeTypeToFilename["application/vnd.oasis.opendocument.text"] = "document.odt";
	mimeTypeToFilename["application/x-7z-compressed"] = "archive.7z";
	mimeTypeToFilename["application/x-bzip"] = "archive.bz";
	mimeTypeToFilename["application/x-bzip2"] = "archive.bz2";
	mimeTypeToFilename["application/x-rar-compressed"] = "archive.rar";
	mimeTypeToFilename["application/zip"] = "archive.zip";
	mimeTypeToFilename["application/x-tar"] = "archive.tar";

	return mimeTypeToFilename;
}
std::string Request::filenameByContentType(const std::string &contentType)
{
	static const std::map<std::string, std::string> mimeTypeToFilename = initMimeTypeToFilename();
	std::map<std::string, std::string>::const_iterator it = mimeTypeToFilename.find(contentType);
	if (it != mimeTypeToFilename.end())
		return it->second;
	return "unknown_file.dat";
}

std::string Request::extensionBasedOnContentType(const std::string &contentType)
{
	static const std::map<std::string, std::string> mimeTypeToExtension = initMimeTypeToExtension();
	std::map<std::string, std::string>::const_iterator it = mimeTypeToExtension.find(contentType);
	if (it != mimeTypeToExtension.end())
		return it->second;
	return ".dat";
}

void Request::processUniqueBodyChunked(std::string &current_buffer)
{
	if (_currentFilename.empty())
	{
		std::string baseDir = "Page/data/";
		ensureDirectoryExists(baseDir);
		std::string filename;
		if (_headers.find("X-Filename") != _headers.end())
			filename = _headers["X-Filename"] + extensionBasedOnContentType(_headers["Content-Type"]);
		else
			filename = filenameByContentType(_headers["Content-Type"]);
		_currentFilename = generateUniqueFilename(baseDir, filename);
		std::string fullPath = baseDir + _currentFilename;

		_currentFile.open(fullPath.c_str(), std::ios::out | std::ios::binary | std::ios::app);
		if (!_currentFile.is_open())
			throw cantOpenFile(500);
	}
	_currentFile << current_buffer;
}

void Request::processUniqueBody(std::string &current_buffer)
{
	if (_currentFilename.empty())
	{
		std::string baseDir = "Page/data/";
		ensureDirectoryExists(baseDir);
		std::string filename;
		if (_headers.find("X-Filename") != _headers.end())
			filename = _headers["X-Filename"] + extensionBasedOnContentType(_headers["Content-Type"]);
		else
			filename = filenameByContentType(_headers["Content-Type"]);
		_currentFilename = generateUniqueFilename(baseDir, filename);
		_currentFilename = generateUniqueFilename(baseDir, filename);
		std::string fullPath = baseDir + _currentFilename;
		_currentFile.open(fullPath.c_str(), std::ios::out | std::ios::binary | std::ios::app);
		if (!_currentFile.is_open())
			throw cantOpenFile(500);
	}
	_FullcurrentFilename = _currentFilename;
	_currentFile << current_buffer;
	_bytesWritten += current_buffer.size();

	std::istringstream contentLengthStream(_headers["Content-Length"]);
	unsigned int contentLength;
	contentLengthStream >> contentLength;

	if (_bytesWritten >= contentLength)
	{
		_currentFile.close();
		_currentFilename.clear();
		_bytesWritten = 0;
		status = PARSING_FINISHED;
		getClient()->setFlag(PREPARING_RESPONSE);
	}
}

void Request::processMultipart(std::string &current_buffer)
{
	if (current_buffer.empty())
		return;
	if (_currentFilename.empty())
	{
		_currentBoundary = extractBoundary(_headers["Content-Type"]);
		_currentFilename = extractFilename(current_buffer);
		std::string baseDir = "Page/data/";
		ensureDirectoryExists(baseDir);
		std::string fullPath = baseDir + _currentFilename;
		_currentFile.open(fullPath.c_str(), std::ios::out | std::ios::binary);
		if (!_currentFile.is_open())
			throw cantOpenFile(500);
		skipHeaders(current_buffer);
	}

	std::string remaining;
	size_t foundAnotherFileBeginning = current_buffer.find("--" + _currentBoundary);
	size_t endFound = current_buffer.find(_currentBoundary + "--");

	// making sure the boundary we found is not the ending one (-2 to take the "--" before)
	if (foundAnotherFileBeginning != std::string::npos && foundAnotherFileBeginning != endFound - 2)
	{
		remaining = current_buffer.substr(foundAnotherFileBeginning);
		current_buffer = current_buffer.substr(0, foundAnotherFileBeginning);
	}

	if (endFound != std::string::npos)
		current_buffer = current_buffer.substr(0, endFound);

	_currentFile << current_buffer;

	if (!remaining.empty())
	{
		_currentFile.close();
		_currentFilename.clear();
		processMultipart(remaining);
	}

	if (endFound != std::string::npos)
	{
		status = PARSING_FINISHED;
		_currentFilename.clear();
		_currentFile.close();
	}
}

void Request::ensureDirectoryExists(const std::string &path)
{
	struct stat st;
	if (stat(path.c_str(), &st) != 0)
		mkdir(path.c_str(), 0777);
}

std::string Request::extractBoundary(const std::string &contentType)
{
	std::size_t pos = contentType.find("boundary=");
	if (pos != std::string::npos)
		return contentType.substr(pos + 9); // 9 pour passer 'boundary=' et ajouter '--' pour correspondre au format des délimiteurs
	return "";
}

std::string Request::extractFilename(const std::string &buffer)
{
	std::string filename;
	size_t filenamePos = buffer.find("filename=\"");
	if (filenamePos != std::string::npos)
	{
		size_t start = filenamePos + 10;
		size_t end = buffer.find("\"", start);
		filename = buffer.substr(start, end - start);
	}
	return filename;
}

std::string Request::parseRequestLine(std::string &current_buffer)
{
	_buffer += current_buffer;
	if (_buffer.find("\r\n") == std::string::npos)
		return ("");

	std::stringstream ss(_buffer);
	std::string line;
	std::getline(ss, line); // As long as we are not able to form a full line, it returns an empty string

	// std::cout << "REQUEST LINE PARSING" << std::endl;
	// std::cout << "Current line is " << line << std::endl;

	std::string remainingString = ss.str().substr(ss.tellg()); // Remainding string after the line
	// std::cout << "Remaining is currently : " << remainingString << std::endl;
	std::istringstream lineStream(line);
	_buffer.clear();

	lineStream >> _method >> _uri >> _httpVersion; // Extract method, URI, and HTTP version from the string stream

	// std::cout << "Method is : " << _method << std::endl;
	// std::cout << "URI is : " << _uri << std::endl;
	// std::cout << "HTTP version : " << _httpVersion << std::endl;

	if (_uri.find('?') != std::string::npos) // If URI contains a query string, extract it
		extractQueryString();

	if (_method.empty() || _uri.empty() || _uri[0] != '/' || _httpVersion.empty() || _httpVersion.substr(0, 5) != "HTTP/")
		throw wrongRLInput(400); // Throw exception for invalid request line input

	if (_httpVersion != "HTTP/1.1")		   // Ensure the HTTP version is supported
		throw unsupportedHTTPVersion(505); // Throw exception for unsupported HTTP version
	status = PARSING_HEADERS;
	return (remainingString);
}

std::string Request::cleanString(std::string toClean)
{
	size_t start = toClean.find_first_not_of(" \t\r\n");
	if (start != std::string::npos)
		toClean.erase(0, start);
	size_t end = toClean.find_last_not_of(" \t\r\n");
	if (end != std::string::npos)
		toClean.erase(end + 1);
	return toClean;
}

std::string Request::parseHeaders(std::string &current_buffer)
{
	// std::cout << "Received the current buffer : " << current_buffer << std::endl;
	_buffer += current_buffer;
	// std::cout << "Merged buffer is currently : " << _buffer << std::endl;
	size_t end = _buffer.find("\r\n\r\n");
	if (end == std::string::npos)
		return ("");
	// std::cout << "We found ending header line at index : " << end << std::endl;

	std::istringstream ss(_buffer);
	std::string line, key, value;
	while (std::getline(ss, line))
	{
		// std::cout << "Current line is : " << line << std::endl;
		if (line == "\r")
			break;
		std::istringstream sS(line); // Create a string stream from the header line
		if (std::getline(sS, key, ':') && std::getline(sS, value))
		{
			value = cleanString(value);
			key = cleanString(key);
			_headers[key] = value;
		}
		else
			throw headerParsingError(400); // Throw exception for invalid header format
	}

	std::string remainingString = _buffer.substr(end + 4);
	// std::cout << "Remaining string is : " << (remainingString.empty() ? "empty" : "not empty") << std::endl;
	_buffer.clear();
	status = CHECKING_HEADERS;
	return remainingString;
}

void Request::parseBody(std::string &current_buffer)
{
	std::string contentType = _headers["Content-Type"];

	if (_headers.find("Transfer-Encoding") != _headers.end() && _headers["Transfer-Encoding"] == "chunked")
		ChunkedBody(current_buffer);
	else if (contentType.find("multipart/form-data") != std::string::npos)
		processMultipart(current_buffer);
	else
		processUniqueBody(current_buffer);
}

void Request::parseRequest(int fd)
{
	std::string current_buffer = readOnce(fd);

	if (status == PARSING_RL)
		current_buffer = parseRequestLine(current_buffer);

	if (status == PARSING_HEADERS)
		current_buffer = parseHeaders(current_buffer);

	if (status == CHECKING_HEADERS)
		checkRequest(current_buffer);

	if (status == PARSING_BODY)
		parseBody(current_buffer);

	if (status == PARSING_FINISHED)
		client->setFlag(PREPARING_RESPONSE);
}

// * This function parses the URI to determine the current location and file path.
// * It extracts the location and file paths from the URI and sets the appropriate
// * member variables based on configuration and file system checks.

void Request::parseUri()
{
	int slash_pos;
	int end_pos;
	std::string temp_loc_path;
	std::string temp_file_path;
	std::string uri;
	uri = this->_uri;
	end_pos = sizeof(uri); // Calculate the size of the URI.
	slash_pos = end_pos;
	temp_loc_path = uri;

	while (1)
	{
		for (size_t i = 0; i < client->get_listen_socket().get_location().size(); ++i)
		{
			if (!client->get_listen_socket().get_location()[temp_loc_path].getName().empty())
			{
				this->_curr_loc = client->get_listen_socket().get_location()[temp_loc_path];
				break; // Exit the loop if a matching location is found.
			}
		}
		if (slash_pos <= 0 || !_curr_loc.getName().empty())
			break; // Stop if no more slashes or current location is set.
		else
		{
			slash_pos = temp_loc_path.find_last_of('/');					 // Find the last slash.
			temp_loc_path = uri.substr(0, slash_pos);						 // Update the location path.
			temp_file_path = uri.substr(slash_pos + 1, end_pos - slash_pos); // Extract the file path.
			if (slash_pos == 0)
			{
				temp_loc_path = "/";
				temp_file_path = uri.substr(slash_pos + 1, end_pos - slash_pos);
			}
		}
	}

	std::string temp_root = client->get_listen_socket().get_root();
	if (!_curr_loc.getRoot().empty())
		temp_root = _curr_loc.getRoot(); // Use current location root if available.

	_file_path = temp_file_path;
	if (!_curr_loc.getIndex().empty() && _file_path.empty())
	{
		_file_path = _curr_loc.getIndex(); // Set file path to index if empty.
		_full_path = temp_root + _curr_loc.getName() + "/" + _file_path;
		replaceDoubleSlashes(_full_path);
		if (access(_full_path.c_str(), F_OK) && _curr_loc.getAutoindex())
			_file_path.clear(); // Clear file path if file doesn't exist and autoindex is enabled.
	}

	if (_curr_loc.empty())
		_file_path = uri; // Use URI as file path if current location is empty.

	_full_path = temp_root + _curr_loc.getName() + "/" + _file_path;
	replaceDoubleSlashes(_full_path);
	if (!_file_path.empty() && isDirectory(_full_path))
		_file_path.clear(); // Clear file path if it's a directory.

	replaceDoubleSlashes(_full_path);
	if (!_file_path.empty() && isDirectory(_full_path))
		_file_path.clear(); // Clear file path again if it's still a directory.

	redirectInURI(); // Perform any necessary URI redirections.
}

void Request::checkLength()
{
	if (_headers.count("Content-Length"))
	{
		std::istringstream contentLengthStream(_headers["Content-Length"]);
		unsigned int contentLength;
		contentLengthStream >> contentLength;
		unsigned int max_size = client->get_listen_socket().get_clientSize();

		if (max_size < contentLength)
			throw bodySize(413);
	}
}

void Request::checkHostName()
{
	std::string host = _headers["Host"];
	std::istringstream iss(host);
	std::string host_name;
	std::getline(iss, host_name, ':');
	if (host_name != this->client->get_listen_socket().get_host() &&
		host_name != this->client->get_listen_socket().get_name())
		throw fileNotFound(404);
}

// * Checks if a file at _full_path is accessible with the specified mode.
// * Throws a 404 error if the file is not found.

void Request::checkFile(int mode)
{
	if (access(_full_path.c_str(), mode))
		throw fileNotFound(404);
	return;
}

// * Checks if the HTTP method used in the request is allowed for the current location or root.
// * Throws a 405 error if the method is not allowed.

void Request::isMethodAllowed()
{
	std::vector<std::string> methods;

	// Get allowed methods based on the current location or root
	if (_curr_loc.empty())
		methods = client->get_listen_socket().get_allow_methods(); // Root allowed methods
	else
		methods = _curr_loc.getAllowMethods(); // Location-specific allowed methods

	// Check if the method is allowed
	for (std::vector<std::string>::iterator it = methods.begin(); it != methods.end(); ++it)
	{
		if (_method == *it)
			return; // Method is allowed
	}

	throw unauthorizedMethod(405); // Throw exception if method is not allowed
}

// * Redirects the URI if the current location has a return directive.
// * Updates the URI and parses it again.

void Request::redirectInURI()
{
	if (_curr_loc.empty())
		return;

	// If the current location has a return URI, set it as the new URI
	if (!_curr_loc.getReturn().empty())
	{
		setURI(_curr_loc.getReturn());
		_curr_loc = location(); // Reset current location
		_hasReturn = true;
		_file_path.clear();
		_full_path.clear();
		parseUri(); // Parse the updated URI
	}
}

// * Checks if a given URI is a folder by examining the presence of '.' or '/'.
// * Returns true if it's a folder, false otherwise.

bool Request::checkfolder(std::string uri)
{
	for (unsigned int i = uri.size(); i != 0; i--)
	{
		if (uri[i - 1] == '.')
			return false; // URI contains a dot, not a folder
		if (uri[i - 1] == '/')
			return true; // URI contains a slash, indicating a folder
	}
	return false;
}

// ------------------------------------------------- ERROR -- //

const char *Request::bodySize::what() const throw()
{
	return ("Body length exceeds server limits.");
}
const char *Request::wrongRLInput::what() const throw()
{
	return ("Request line arguments doesn't fit format.");
}
const char *Request::headerParsingError::what() const throw()
{
	return ("Header parsing error.");
}
const char *Request::invalidContentLength::what() const throw()
{
	return ("Negative length content specified.");
}
const char *Request::shorterBodyContent::what() const throw()
{
	return ("Mismatch between specified content-length and actuel content size (shorter).");
}
const char *Request::longerBodyContent::what() const throw()
{
	return ("Mismatch between specified content-length and actuel content size (longer).");
}
const char *Request::contentLengthUnspecified::what() const throw()
{
	return ("Content-length was not specified.");
}
const char *Request::unauthorizedMethod::what() const throw()
{
	return ("Unauthorized method requested.");
}
const char *Request::fileNotFound::what() const throw()
{
	return ("File not found");
}
const char *Request::unsupportedHTTPVersion::what() const throw()
{
	return ("Unsupported HTTP Version. Please conform to HTTP 1.1 only.");
}

const char *Request::chunkSizeError::what() const throw()
{
	return ("Failed to read chunk size.");
}
const char *Request::chunkDataError::what() const throw()
{
	return ("Failed to read chunk data.");
}

const char *Request::cantOpenFile::what() const throw()
{
	return ("Error while opening/creating file.");
}
