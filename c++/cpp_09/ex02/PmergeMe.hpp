#pragma once

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <ctime>
# include <cstring>
# include <cctype>
# include <limits>
# include <iomanip>

class PmergeMe
{
	private:
		std::vector<int> _vect;
		std::list<int> _lst;
		double _timer;
	public:
		PmergeMe();
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &f);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &f);

		void algo_vector();
		void algo_list();


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
