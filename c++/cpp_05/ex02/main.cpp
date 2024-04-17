#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int main()
{
	{ShrubberyCreationForm a = ShrubberyCreationForm("test");
	a.action();}
	std::cout << std::endl;
	{RobotomyRequestForm b = RobotomyRequestForm("Robot");
	b.action();}
		{RobotomyRequestForm b = RobotomyRequestForm("Robot");
	b.action();}
		{RobotomyRequestForm b = RobotomyRequestForm("Robot");
	b.action();}
		{RobotomyRequestForm b = RobotomyRequestForm("Robot");
	b.action();}
	std::cout << std::endl;
	{PresidentialPardonForm c = PresidentialPardonForm("Pres");
	c.action();}
	return 0;
}
