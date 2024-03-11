#include <iostream>

int main()
{
	std::string a = "HI THIS IS BRAIN";

	std::cout << "string address : " << &a << std::endl;
	std::cout << "string pointer address : " << a << std::endl;
	std::cout << "string ref address : " << &a << std::endl;

	std::cout << "string value : " << a << std::endl;
	std::cout << "string pointer value : " << a << std::endl;
	std::cout << "string ref value : " << a << std::endl;
	return 0;
}