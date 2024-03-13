#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arg" << std::endl;
		return 1;
	}
	Harl a;
	a.complain(argv[1]);
	return 0;
}
