#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	int i = 1;

	if (argc < 2)
	{
		std::cout << "Wrong number of argument" << std::endl;
		return 0;
	}
	for (; argc != i; i++)
	{
		try
		{
			ScalarConverter::convert(argv[i]);
			if (i != argc - 1)
				std::cout << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << "Exeption : " << e.what() << std::endl;
		}

	}
	return 0;
}
