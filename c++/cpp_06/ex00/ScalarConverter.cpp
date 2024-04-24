#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default Constructor Called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &f)
{
	(void)f;
	std::cout << "Copie Constructor Called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &f)
{
	(void)f;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor Called" << std::endl;
}

const char *ScalarConverter::ImpossibleException::what() const throw()
{
	return "Convert impossible";
}

//------------------------------------------------------------

void ScalarConverter::convert(const std::string &input)
{
	if (false)
		throw ImpossibleException();
	if (true)
		toChar(input);
	if (isInt(input))
		toInt(input);
	if (isFloat(input))
		toFloat(input);
	if (isDouble(input))
		toDouble(input);
}

//------------------------------------------------------------

void ScalarConverter::toChar(const std::string &input)
{
	std::cout << "Char : " << input << std::endl;
}

//------------------------------------------------------------

bool isInt(const std::string &input)
{
	return true;
}

void ScalarConverter::toInt(const std::string &input)
{
	int i = std::stoi(input);
	std::cout << "int : " << i << std::endl;
}

//------------------------------------------------------------

bool isFloat(const std::string &input)
{
	return true;
}

void ScalarConverter::toFloat(const std::string &input)
{
	float i = std::stof(input);
	std::cout << "Float : " << i << std::endl;
}

//------------------------------------------------------------

bool isDouble(const std::string &input)
{
	return true;
}

void ScalarConverter::toDouble(const std::string &input)
{
	double i = std::stod(input);
	std::cout << "Double : " << i << std::endl;
}
