#pragma once

# include <iostream>
# include <vector>
# include <stack>
# include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>() {}
		MutantStack<T>(const MutantStack &f) {(void)f;}
		~MutantStack<T>() {}
		MutantStack<T> &operator=(const MutantStack &f) {(void)f;return *this;}

		typedef typename std::stack<T>::container_type::iterator 		iterator;

		iterator begin()
		{
			return std::stack<T>::c.begin();
		}

		iterator end()
		{
			return std::stack<T>::c.end();
		}
};
