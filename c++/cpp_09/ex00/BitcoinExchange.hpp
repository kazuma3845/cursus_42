#pragma once

# include <iostream>
# include <map>
# include <algorithm>
# include <fstream>
# include <string>

# define DATA "../data.csv"

class BitcoinExchange
{
	private:
		std::map<std::string, double> _data;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &f);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &f);

		void main_fonct(char *argv);
		void check(std::string line);
		void calcul(std::string line);

		class ExceptionWrongDate : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class ExceptionWrongNum : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class ExceptionNegativNum : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class ExceptionWronginput : public std::exception
		{
			public:
				const char *what() const throw();
		};
};
