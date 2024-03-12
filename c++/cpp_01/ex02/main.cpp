#include <iostream>

int main()
{
	std::string a = "HI THIS IS BRAIN";
	std::string *b = &a;
	std::string &c = a;

	std::cout << "string address : " << &a << std::endl;
	std::cout << "string pointer address : " << &b << std::endl;
	std::cout << "string ref address : " << &c << std::endl << std::endl;

	std::cout << "string value : " << a << std::endl;
	std::cout << "string pointer value : " << *b << std::endl;
	std::cout << "string ref value : " << c << std::endl;
	return 0;
}