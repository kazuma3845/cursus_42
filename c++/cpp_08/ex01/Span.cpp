#include "Span.hpp"

Span::Span() : _n(0)
{
}

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span &f) : _n(f._n)
{
}

Span::~Span()
{
}

Span Span::operator=(const Span &f)
{
	(void)f;
	return *this;
}

void Span::addNumber(unsigned int n)
{
	if (this->_temp.size() < this->_n)
		this->_temp.push_back(n);
	else
		throw ExceptionNoNumber();
}

void Span::addMultiNumber(unsigned int n)
{
	srand((long)this);
	for (unsigned int i = 0; i < n; i++)
	{
		addNumber(rand() % INT_MAX);
	}
}

unsigned int Span::shortestSpan()
{
	unsigned int i = 0;

	if (this->_temp.size() <= 1)
		throw ExceptionOneNumber();
	
	return i;
}

unsigned int Span::longestSpan()
{
	unsigned int i = 0;
	
	if (this->_temp.size() <= 1)
		throw ExceptionOneNumber();
	std::vector<int> copy = this->_temp;
	for (unsigned int j = 0; j < this->_temp.size(); j++)
	{
		
	}
	return i;
}

const char *Span::ExceptionNoNumber::what() const throw()
{
	return "No space in the vector";
}

const char *Span::ExceptionOneNumber::what() const throw()
{
	return "No distance found";
}
