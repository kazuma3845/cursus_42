#include "RPN.hpp"

RPN::RPN()
{
}

int find_op(char argv)
{
	std::string op[4] = {"+", "-", "*", "/"};
	for(int i = 0; i < 4; i++)
	{		
		if (op[i] == std::string(1, argv))
			return i ;
	}
	return 5;
}

RPN::RPN(char *argv)
{
	unsigned int oper = 0;
	int length = strlen(argv);
	for(int i = length - 1; i >= 0; i--)
	{
		if (isdigit(argv[i]))
			this->_stack.push(argv[i]);
		else if (!isdigit(argv[i]) && argv[i] != ' ')
		{
			int j = find_op(argv[i]);
			if (j > 4)
				throw ExceptionWrongOperator();
			oper++;
		}
	}
	if (oper + 1 != this->_stack.size())
		throw ExceptionWrongNum();
}

RPN::RPN(const RPN &f)
{
	(void)f;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &f)
{
	(void)f;
	return *this;
}

void RPN::calcul(char *argv)
{
	int result = this->_stack.top() - 48;
	this->_stack.pop();
	int i;

	for(int j = 0; argv[j]; j++)
	{
		if (!isdigit(argv[j]) && argv[j] != ' ')
		{
			i = find_op(argv[j]);
			if (i > 4)
				throw ExceptionWrongOperator();
			int first = result;
			int second = this->_stack.top() - 48;
			this->_stack.pop();
			switch(i)
			{
				case 0:
				{
					result = first + second;
					// std::cout << "Case 0 | First: " << first << " | operator: +" << " | second: " << second << " | result: " << result << std::endl;
					break ;
				}
				case 1:
				{
					result = first - second;
					// std::cout << "Case 1 | First: " << first << " | operator: -" << " | second: " << second << " | result: " << result << std::endl;
					break ;
				}
				case 2:
				{
					result = first * second;
					// std::cout << "Case 2 | First: " << first << " | operator: *" << " | second: " << second << " | result: " << result << std::endl;
					break ;
				}
				case 3:
				{
					result = first / second;
					// std::cout << "Case 3 | First: " << first << " | operator: /" << " | second: " << second << " | result: " << result << std::endl;
					break ;
				}
			}
		}
	}
	std::cout << "Result: " << result << std::endl;
}

const char *RPN::ExceptionWrongNum::what() const throw()
{
	return " Number and Operator not equal";
}

const char *RPN::ExceptionWrongOperator::what() const throw()
{
	return "Operator not found";
}
