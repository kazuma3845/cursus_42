#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int main()
{
	// {ShrubberyCreationForm a = ShrubberyCreationForm("test");
	// a.action();}
	std::cout << std::endl;
	std::cout << std::endl;
	{RobotomyRequestForm b = RobotomyRequestForm("Robot");
	b.action();}
	{RobotomyRequestForm d = RobotomyRequestForm("Robot");
	d.action();}
	{RobotomyRequestForm e = RobotomyRequestForm("Robot");
	e.action();}
	{RobotomyRequestForm f = RobotomyRequestForm("Robot");
	f.action();}
	std::cout << std::endl;
	std::cout << std::endl;
	{PresidentialPardonForm c = PresidentialPardonForm("Pres");
	c.action();}
	std::cout << std::endl;
	return 0;
}
