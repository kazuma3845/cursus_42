#pragma once

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <ctime>
#include <cstring>
#include <cctype>

class PmergeMe
{
	private:
		std::vector<int> _vect;
		std::list<int> _lst;
	public:
		PmergeMe();
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &f);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &f);

		void algo();

		class ExceptionBadArgument : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class ExceptionDoubleNumber : public std::exception
		{
			public:
				const char *what() const throw();
		};
};
