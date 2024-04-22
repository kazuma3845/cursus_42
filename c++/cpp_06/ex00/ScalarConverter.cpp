#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor creat" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &f)
{
	std::cout << "Copie constructor creat" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &f)
{
	(void)f;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Constructor destroy" << std::endl;
}