#include "autoindex.hpp"

std::string AutoIndex::create(std::string uri, std::string root) {
    std::string page;
    std::string dirName(uri.c_str());
    std::string purePath(uri.substr(root.size(), uri.size()).c_str());
    DIR* dir = opendir(uri.c_str());
    page = "<html>\n"
           "    <head>\n"
           "        <title>Index of " + purePath + "</title>\n"
           "        <style>\n"
           "            table { width: 100%; border-collapse: collapse; }\n"
           "            th, td { padding: 8px; text-align: left; border-bottom: 1px solid #ddd; }\n"
           "            th { background-color: #f2f2f2; }\n"
           "        </style>\n"
           "    </head>\n"
           "    <body>\n"
           "        <h1>Index of " + purePath + "</h1>\n"
           "        <table>\n"
           "            <tr><th>Name</th><th>Size</th></tr>\n";

    if (dir == NULL) {
        // std::cerr << "Error: Directory not opened: " << dirName << std::endl;
        return "";
    }

    for (struct dirent* newdir = readdir(dir); newdir; newdir = readdir(dir)) {
        std::string name(newdir->d_name);
        std::string filePath = dirName + "/" + name;
        page += addLine(name, filePath, purePath);
    }

    page += "        </table>\n"
            "    </body>\n"
            "</html>\n";
    closedir(dir);
    return page;
}

std::string AutoIndex::addLine(const std::string& name, const std::string& path, std::string& purePath) {
    struct stat fileStat;
    if (stat(path.c_str(), &fileStat) == -1) {
        perror("stat");
        return "";
    }
    if (name[0] == '.')
        return "";
    std::stringstream ss;
    ss << "            <tr>"
       << "<td><a href=\"" << "/" + purePath + name << "\">" << name << "</a></td>"
       << "<td>" << ((S_ISDIR(fileStat.st_mode)) ? "-" : fileSize(fileStat.st_size)) << "</td>"
       << "</tr>\n";
    return ss.str();
}

std::string AutoIndex::fileSize(off_t size) {
    std::stringstream ss;
    if (size >= 1024 * 1024) {
        ss << size / (1024 * 1024) << "M";
    } else if (size >= 1024) {
        ss << size / 1024 << "K";
    } else {
        ss << size << "B";
    }
    return ss.str();
}
