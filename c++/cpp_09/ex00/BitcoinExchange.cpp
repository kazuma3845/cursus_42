#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream myfile;
	std::string date;
	std::string line;
	double value = 0;
	std::string val;

	myfile.open(DATA);
	if (!myfile)
		throw ExceptionWronginput();
	std::getline(myfile, line);
	while (std::getline(myfile, line))
	{
		date = line.substr(0,10);
		val = line.substr(11, line.size());
		value = std::stod(val);
		this->_data[date] = value;
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
	if (!myfile)
		throw ExceptionWronginput();
	std::getline(myfile, line);
	if (line.empty())
		throw ExceptionWronginput();
	while (std::getline(myfile, line))
	{
		try
		{
			check(line);
			calcul(line);
		}
		catch(ExceptionWrongDate &e)
		{
			std::cerr << "Error: "<< e.what() << " => " << line.substr(0, 10) << std::endl;
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
	if (line.size() < 13)
		throw ExceptionWrongDate();
	if (!check_date(line))
		throw ExceptionWrongDate();
	double value = stod(line.substr(13, line.size()));
	if (value < 0)
		throw ExceptionNegativNum();
}

bool BitcoinExchange::check_date(std::string line)
{
	if (line[4] != '-' || line[7] != '-' || line[10] != 32 || line[12] != 32 || line[11] != '|')
		return false;
	for (unsigned int i = 0; i < line.size(); i++)
	{
		if (i == 4 || i == 7 || i > 9)
			;
		else if (!isdigit(line[i]))
			return false;
	}
	int year = stoi(line.substr(0, 4));
	int month = stoi(line.substr(5, 7));
	int day = stoi(line.substr(8, 10));

	if (year < 2009 || year > 2022)
		return false;
	if (month < 1 || month > 12 || (year == 2022 && month > 3))
		return false;
	if (day < 1 || (month == 2 && day > 28))
		return false;
	if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) || day < 1)
		return false;
	if (((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) || day < 1)
		return false;
	if (year == 2022 && month == 3 && day > 29)
		return false;
	if ((year == 2009 && month == 1 && day < 2) || (year == 2009 && month < 1))
		return false;
	return true;
}

void BitcoinExchange::calcul(std::string line)
{
	double num = stod(line.substr(13, line.size()));
	if (num > 1000)
		throw ExceptionWrongNum();
	std::string date = line.substr(0, 10);
	if (this->_data.find(date) == this->_data.end() && num != 0)
	{
		while (this->_data.find(date) == this->_data.end())
		{
			int year = stoi(date.substr(0, 4));
			int month = stoi(date.substr(5, 7));
			int day = stoi(date.substr(8, 10));
			if (day > 1)
			{
				day -= 1;
			}
			else if (check_month(&day, month))
			{
				month -= 1;
			}
			else
			{
				day += 30;
				month += 11;
				year -= 1;
			}
			if (day < 10 && month < 10)
				date = std::to_string(year) + "-0" + std::to_string(month) + "-0" + std::to_string(day);
			else if (day < 10)
				date = std::to_string(year) + "-0" + std::to_string(month) + "-" + std::to_string(day);
			else if (month < 10)
				date = std::to_string(year) + "-0" + std::to_string(month) + "-" + std::to_string(day);
			else
				date = std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day);
		}
	}
	double value = this->_data.find(date)->second * num;
	// std::cout << "Num: " << num << " | Data: " << this->_data[date] << " | ";
	std::cout << line.substr(0, 10) << " => " << num << " = " << value << std::endl;
}

bool BitcoinExchange::check_month(int *day, int month)
{
	if (month == 1)
		return false;
	if (month == 3)
	 *day += 27;
	if (month == 12 || month == 10 || month == 7 || month == 5)
		*day += 29;
	else
		*day += 30;
	return true;
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
