#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
		{
			std::cout << "Error: could not open file." << std::endl;
			return 1;
		}
		BitcoinExchange *value = new BitcoinExchange();
		value->main_fonct(argv[1]);
		delete value;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
