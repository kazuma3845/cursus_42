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
		BitcoinExchange val;
		val.main_fonct(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
