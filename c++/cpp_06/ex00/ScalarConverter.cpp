#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

const char *ScalarConverter::ImpossibleException::what() const throw()
{
	return "Convert impossible";
}

//------------------------------------------------------------

void ScalarConverter::convert(const std::string &input)
{
	if (isChar(input))
		toChar(input);
	else if (isInt(input))
		toInt(input);
	else if (isFloat(input))
		toFloat(input);
	else if (isDouble(input))
		toDouble(input);	
	else
		throw ImpossibleException();
}

//------------------------------------------------------------

bool ScalarConverter::isChar(const std::string &input)
{
	if (input.size() == 1)
		return true;
	return false;
}

void ScalarConverter::toChar(const std::string &input)
{
	char c = input[0];
	double d = static_cast<double>(c);
	float f = static_cast<float>(c);
	int i = static_cast<int>(c);
	if (isprint(c))
		std::cout << "Char : " << c << std::endl;
	else
		std::cout << "Char : non displayable" << std::endl;
	std::cout << "Int : " << i << std::endl;
	std::cout << "Float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "Double : " << d << std::endl;
}

//------------------------------------------------------------

bool ScalarConverter::isInt(const std::string &input)
{
	if (input.empty())
		return false;
	if (!input.compare("nan") || !input.compare("nanf") || !input.compare("-inff") || !input.compare("+inff") || !input.compare("inff") || !input.compare("-inf") || !input.compare("+inf") || !input.compare("inf"))
		return false;
	size_t j = 0;
	while (j < input.size() && std::isspace(input[j]))
		j++;
	if (j == input.size())
		return false;
	if (input[j] == '+' || input[j] == '-')
		j++;
	if (j == input.size() || !std::isdigit(input[j]))
		return false;
	for (; j < input.size() && std::isdigit(input[j]); j++)
		;
	if (j != input.size())
		return false;
	long i = std::stol(input);
	if (i > INT_MAX || i < INT_MIN)
		return false;
	return true;
}

void ScalarConverter::toInt(const std::string &input)
{
	int i = std::stoi(input);
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
	{
		if (isprint(c))
			std::cout << "Char : '" << c << "'" << std::endl;
		else
			std::cout << "Char : non displayable" << std::endl;
	}
	else
		std::cout << "Char : impossible" << std::endl;
	std::cout << "Int : " << i << std::endl;
	std::cout << "Float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "Double : " << d << std::endl;
}

//------------------------------------------------------------

bool ScalarConverter::isFloat(const std::string &input)
{
	if (input.empty())
		return false;
	if (!input.compare("nan") || !input.compare("nanf") || !input.compare("-inff") || !input.compare("+inff") || !input.compare("inff") || !input.compare("-inf") || !input.compare("+inf") || !input.compare("inf"))
		return true;
	size_t j = 0;
	while (j < input.size() && std::isspace(input[j]))
		j++;
	if (j == input.size())
		return false;
	if (input[j] == '+' || input[j] == '-')
		j++;
	if (j == input.size() || !std::isdigit(input[j]))
		return false;
	for (; j < input.size() && (std::isdigit(input[j]) || input[j] == '.'); j++)
		;
	if (!((input[j] == 'f' || input[j] == 'F') && j + 1 == input.size()))
		return false;
	long i = std::stol(input);
	if (i > INT_MAX || i < INT_MIN)
		return false;
	return true;
}

void ScalarConverter::toFloat(const std::string &input)
{
	float f = std::stof(input);
	int i = static_cast<int>(f);
	char c = static_cast<char>(f);
	double d = static_cast<double>(f);

	if (f >= std::numeric_limits<char>::min() && f <= std::numeric_limits<char>::max())
	{
		if (isprint(c))
			std::cout << "Char : '" << c << "'" << std::endl;
		else
			std::cout << "Char : non displayable" << std::endl;
	}
	else
		std::cout << "Char : impossible" << std::endl;
	if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
		std::cout << "Int : " << i << std::endl;
	else
		std::cout << "Int : impossible" << std::endl;
	std::cout << "Float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "Double : " << d << std::endl;
}

//------------------------------------------------------------

bool ScalarConverter::isDouble(const std::string &input)
{
	if (input.empty())
		return false;
	if (!input.compare("nan") || !input.compare("nanf") || !input.compare("-inff") || !input.compare("+inff") || !input.compare("inff") || !input.compare("-inf") || !input.compare("+inf") || !input.compare("inf"))
		return true;
	size_t j = 0;
	while (j < input.size() && std::isspace(input[j]))
		j++;
	if (j == input.size())
		return false;
	if (input[j] == '+' || input[j] == '-')
		j++;
	if (j == input.size() || !std::isdigit(input[j]))
		return false;
	for (; j < input.size() && (std::isdigit(input[j]) || input[j] == '.'); j++)
		;
	if (j < input.size() && (input[j] == 'e' || input[j] == 'E'))
	{
		j++;
		if (j < input.size() && (input[j] == '+' || input[j] == '-'))
			j++;
		for (; j < input.size() && std::isdigit(input[j]); j++)
			;
	}
	if (j != input.size())
		return false;
	long i = std::stol(input);
	if (i > INT_MAX || i < INT_MIN)
		return false;
	return true;
}

void ScalarConverter::toDouble(const std::string &input)
{
	double d = std::stod(input);
	float f = static_cast<float>(d);
	int i = static_cast<int>(d);
	char c = static_cast<char>(d);

	if (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max())
	{
		if (isprint(c))
			std::cout << "Char : '" << c << "'" << std::endl;
		else
			std::cout << "Char : non displayable" << std::endl;
	}
	else
		std::cout << "Char : impossible" << std::endl;
	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
		std::cout << "Int : " << i << std::endl;
	else
		std::cout << "Int : impossible" << std::endl;
	std::cout << "Float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "Double : " << d << std::endl;
}
