#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream myfile;
	std::string date;
	std::string line;
	double value;
	std::string val;

	myfile.open(DATA);
	std::getline(myfile, line);
	while (std::getline(myfile, line))
	{
		date = line.substr(0,10);
		int i = 0;
		int j = 0;
			while (line[i] != ',')
				i++;
			i++;
			while (line[i])
			{
				val[j++] = line[i++];
			}
		std::cout << " <<<<< " << val << " >>>>>";
		value = std::stod(val);
		std::cout << " <<<<< " << value << " >>>>>";
		this->_data[date] = value;
		std::cout << std::endl << this->_data.find(date)->second << " | Valu: " << value << std::endl;
		if (date.compare("2012-01-11") == 0)
			break ;
	}
	myfile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &f)
{
	(void)f;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &f)
{
	(void)f;
	return *this;
}

void BitcoinExchange::main_fonct(char *argv)
{
	std::ifstream myfile;
	std::string line;

	myfile.open(argv);
	std::getline(myfile, line);
	while (std::getline(myfile, line))
	{
		try
		{
			check(line);
			calcul(line);
		}
		catch(std::exception& e)
		{
			std::cerr << "Error: "<< e.what() << std::endl;
		}
	}
	myfile.close();
}

void BitcoinExchange::check(std::string line)
{
	double value = stod(line.substr(13, 20));
	if (value < 0)
		throw ExceptionNegativNum();
}

void BitcoinExchange::calcul(std::string line)
{
	double num = stod(line.substr(13, 20));
	if (num > 1000)
		throw ExceptionWrongNum();
	std::string date;
	std::map<std::string, double>::iterator it;
	date = line.substr(0, 10);
	if (this->_data.find(date)->second == 0 && num != 0)
	{
		throw ExceptionWrongDate();
	}
	// std::cout << "Num: " << num << ", data: " << this->_data.find(date)->second << std::endl;
	// double value = this->_data[date] * num;
	// std::cout << line.substr(0, 10) << " => " << num << " = " << value << std::endl;
}

const char *BitcoinExchange::ExceptionNegativNum::what() const throw()
{
	return "not a positive number.";
}

const char *BitcoinExchange::ExceptionWrongDate::what() const throw()
{
	return "bad input";
}

const char *BitcoinExchange::ExceptionWrongNum::what() const throw()
{
	return "too large a number.";
}

const char *BitcoinExchange::ExceptionWronginput::what() const throw()
{
	return "could not open file.";
}