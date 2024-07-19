#pragma once
#include <exception>
#include <string>

class ErrorWebServ : public std::exception {
public:
    ErrorWebServ(int errorCode) : errorCode(errorCode) {} //Constructor with ErrorCode

    int getErrorCode() const { return errorCode; }
    virtual const char* what() const throw() = 0;

private:
    int errorCode;
};