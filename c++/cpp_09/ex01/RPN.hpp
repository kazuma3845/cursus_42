#pragma once

# include <iostream>
# include <algorithm>
# include <stack>

class RPN
{
	private:
		std::stack<char> _stack;
	public:
		RPN();
		RPN(char *argv);
		RPN(const RPN &f);
		~RPN();
		RPN &operator=(const RPN &f);

		void calcul(char *argv);

		class ExceptionWrongOperator : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class ExceptionWrongNum : public std::exception
		{
			public:
				const char *what() const throw();
		};
};