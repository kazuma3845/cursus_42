#include "iter.hpp"

void print_char(char c)
{
    std::cout << c;
}

int main()
{
	char array[13] = "Hello World\n";
	iter(array, sizeof(array), print_char);
	return 0;
}
