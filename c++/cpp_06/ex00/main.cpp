#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of argument" << std::endl;
		return 0;
	}
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch(std::exception &e)
	{
		std::cerr << "Exeption : " << e.what() << std::endl;
	}
	return 0;
}
