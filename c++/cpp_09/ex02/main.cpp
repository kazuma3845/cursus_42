#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	try
	{
		PmergeMe a(argc, argv);
		a.algo_vector();
		a.algo_list();
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception catch: " << e.what() << std::endl;
	}
	return 0;
}
