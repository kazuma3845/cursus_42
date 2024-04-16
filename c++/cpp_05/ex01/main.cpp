#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		Bureaucrat a = Bureaucrat("John", 50);
		std::cout << a << std::endl;
		Form b = Form("Certificat of death", 49, 10);
		std::cout << b;
		b.beSigned(a);
		b.signForm(a);
	}


	std::cout << std::endl;
	{
		Bureaucrat a = Bureaucrat("John", 1);
		std::cout << a << std::endl;
		Form b = Form("Certificat of death", 10, 1);
		std::cout << b;
		b.beSigned(a);
		b.signForm(a);
	}


	std::cout << std::endl;
	{
		Bureaucrat a = Bureaucrat("John", 1);
		std::cout << a << std::endl;
		Form b = Form("Certificat of death", 0, 0);
		std::cout << b;
		b.beSigned(a);
		b.signForm(a);
	}
	return 0;
}
