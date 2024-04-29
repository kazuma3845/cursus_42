#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	Base *base;
	int result = std::rand() % 3;
	switch(result)
	{
		case 1:
			base = new A();
			// std::cout << "Case 1" << std::endl;
			break ;
		case 2:
			base = new B();
			// std::cout << "Case 2" << std::endl;
			break ;
		default:
			base = new C();
			// std::cout << "Case 3" << std::endl;
			break ;
	}
	return base;
}

void identify(Base *p)
{
		A* new_a = dynamic_cast<A*>(p);
		B* new_b = dynamic_cast<B*>(p);
		C* new_c = dynamic_cast<C*>(p);
		if (new_a != NULL)
			std::cout << "Class A" << std::endl;
		else if (new_b != NULL)
			std::cout << "Class B" << std::endl;
		else if (new_c != NULL)
			std::cout << "Class C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A new_a = dynamic_cast<A&>(p);
		std::cout << "Class A" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		B new_b = dynamic_cast<B&>(p);
		std::cout << "Class B" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		C new_c = dynamic_cast<C&>(p);
		std::cout << "Class C" << std::endl;
	}
	catch (std::exception &e)
	{
	}
}

int main()
{
	std::srand(std::time(NULL));

	Base *base;
	base = generate();
	std::cout << "First identify : ";
	identify(base);
	std::cout << "Second identify : ";
	identify(*base);
	delete base;
	return 0;
}
