#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
#include <sys/stat.h>
#include <cstring>
#include <unistd.h>
#include "../errors/ErrorWebServ.hpp"

#define BUFFER_SIZE 4096

void replaceDoubleSlashes(std::string &str);
bool isDirectory(std::string &path);
std::string readOnce(int fd);

class connectionCloseEarly : public ErrorWebServ
{
public:
	connectionCloseEarly(int errorCode) : ErrorWebServ(errorCode) {}
	const char *what() const throw();
};

class errorReadingFD : public ErrorWebServ
{
public:
	errorReadingFD(int errorCode) : ErrorWebServ(errorCode) {}
	const char *what() const throw();
};