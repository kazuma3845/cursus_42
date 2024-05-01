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
	unsigned int i;

	if (this->_temp.size() <= 1)
		throw ExceptionOneNumber();

	std::sort(this->_temp.begin(), this->_temp.end());
    i = (unsigned int)this->_temp[1] - (unsigned int)this->_temp[0];
    for (size_t n = 0; n < this->_temp.size(); n++)
	{
		if (i > ((unsigned int)this->_temp[n + 1] - (unsigned int)this->_temp[n]))
    		i = (unsigned int)this->_temp[n + 1] - (unsigned int)this->_temp[n];
	}
	return i;
}

unsigned int Span::longestSpan()
{
	unsigned int i;
	std::vector<int>::iterator min;
	std::vector<int>::iterator max;

	if (this->_temp.size() <= 1)
		throw ExceptionOneNumber();

	min = std::min_element(this->_temp.begin(), this->_temp.end());
	max = std::max_element(this->_temp.begin(), this->_temp.end());
	i = (long)(*max) - (long)(*min);
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
