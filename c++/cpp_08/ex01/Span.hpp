#pragma once

#include <iostream>
#include <vector>
# include <algorithm>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _temp;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &f);
		Span operator=(const Span &f);
		~Span();

		void addNumber(unsigned int n);
		void addMultiNumber(unsigned int n);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		class ExceptionNoNumber : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class ExceptionOneNumber : public std::exception
		{
			public:
				const char *what() const throw();
		};
};
