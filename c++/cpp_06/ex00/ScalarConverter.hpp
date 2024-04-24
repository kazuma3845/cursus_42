#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &f);
		ScalarConverter &operator=(const ScalarConverter &f);
		~ScalarConverter();

		static void	convert(const std::string &input);

		class ImpossibleException : public std::exception
		{
			public:
				const char *what() const throw();
		};

	private:
		static void toChar(const std::string &input);
		static void toInt(const std::string &input);
		static void toFloat(const std::string &input);
		static void toDouble(const std::string &input);

		static bool isInt(const std::string &input);
		static bool isFloat(const std::string &input);
		static bool isDouble(const std::string &input);


};

#endif