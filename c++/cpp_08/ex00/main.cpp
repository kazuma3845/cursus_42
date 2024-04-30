#include "easyfind.hpp"

int main( void )
{
    std::vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(2);
    num.push_back(4);
    num.push_back(5);
	easyfind(num, 2);
	easyfind(num, 5);
	easyfind(num, 1);
	easyfind(num, 8);

	return 0;
}
