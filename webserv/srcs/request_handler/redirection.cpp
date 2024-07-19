#include "redirection.hpp"

void Redirection::path(Request &a, Response &resp)
{
	if (checkfolder(a.getURI()))
		folderpath(a, resp);
	else
		check_ext_cgi(a, resp);
}

bool Redirection::checkfolder(std::string uri)
{
	for (unsigned int i = uri.size(); i != 0; i--)
	{
		if (uri[i - 1] == '.')
			return false;
		if (uri[i - 1] == '/')
			return true;
	}
	return false;
}

void Redirection::folderpath(Request &a, Response &resp)
{
	if (a.getFilePath().empty())
	{
		if (a.getCurr_loc().getAutoindex() == true)
		{
			AutoIndex index;
			resp.setBody(index.create(a.getFullPath(), a.getClient()->get_listen_socket().get_root()));
			resp.setStatusCode(200);
			a.getClient()->setFlag(RESPONSE_OK);
		}
		else
			throw Forbidden(403);
	}
	else
	{
		std::string path = a.getURI() + a.getCurr_loc().getIndex();
		a.setURI(path);
		check_ext_cgi(a, resp);
	}
}

void Redirection::check_ext_cgi(Request &a, Response &resp)
{
	if (!a.getCurr_loc().getCgiPath().empty() && checkCgiExt(a.getURI(), a))
	{
		CgiHandler cgi(a);
		resp.setContentType("text/plain");
		resp.setBody(cgi.execute(a.getFullPath(), resp));
		if (a.getMethod().compare("POST") == 0)
		{
			std::string file = "Page/data/" + a.getCurrentFilename();
			remove(file.c_str());
		}
		a.getClient()->setFlag(RESPONSE_OK);
	}
	else if (checkMimeExt(a.getURI()))
	{
		Handler handler(a, resp);
		handler.process();
	}
	else
		throw UnsupportedMediaType(415);
}

bool Redirection::checkCgiExt(std::string uri, Request &a)
{
	std::string ext = uri.substr(uri.find('.'), uri.size());
	std::vector<std::string> cgiext = a.getCurr_loc().getCgiExt();
	if (cgiext.empty())
		return false;
	for (unsigned int i = 0; i < a.getCurr_loc().getCgiExt().size(); i++)
	{
		if (ext.compare(cgiext[i]) == 0)
			return true;
	}
	return false;
}

bool Redirection::checkMimeExt(std::string uri)
{
	std::string ext = uri.substr(uri.find('.'), uri.size());
	std::string mime[77] = {".aac", ".abw", ".apng", ".arc", ".avif", ".avi", ".azw",\
	".bin", ".bmp", ".bz", ".bz2",\
	".cda", ".csh", ".css", ".csv",\
	".doc", ".docx",\
	".eot", ".epub",\
	".gz", ".gif",\
	".htm", ".html",\
	".ico", ".ics",\
	".jar", ".jpeg", ".jpg", ".json", ".js", ".jsonld",\
	".mid", ".midi", ".mjs", ".mp3", ".mp4", ".mpeg", ".mpkg",\
	".odp", ".ods", ".odt", ".oga", ".ogv", ".ogx", ".opus", ".otf",\
	".png", ".pdf", ".php", ".ppt", ".pptx",\
	".rar", ".rtf",\
	".sh", ".svg",\
	".tar", ".tif", ".tiff", ".ts", ".ttf", ".txt",\
	".vsd",\
	".wav",	".weba", ".webm", ".webp", ".woff", ".woff2",\
	".xhtml", ".xls", ".xlsx", ".xml", ".xul",\
	".zip", ".3gp", ".3g2", ".7z"};
	for (unsigned int i = 0; i < 77; i++)
	{
		if (ext.compare(mime[i]) == 0)
			return true;
	}
	return false;
}

const char* Redirection::UnsupportedMediaType::what() const throw()
{
    return "Unsupported Media Type";
}

const char* Redirection::Forbidden::what() const throw()
{
    return "Forbidden";
}
