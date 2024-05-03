#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong Number of argument" << std::endl;
		return 1;
	}
	try
	{
		RPN stack(argv[1]);
		stack.calcul(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception catch: " << e.what() << std::endl;
	}
	return 0;
}
