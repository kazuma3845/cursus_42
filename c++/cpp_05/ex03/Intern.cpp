#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Creat" << std::endl;
	this->tab[0] = new ShrubberyCreationForm();
	this->tab[1] = new RobotomyRequestForm();
	this->tab[2] = new PresidentialPardonForm();
}

Intern::Intern(const Intern& f)
{
	(void)f;
	std::cout << "Copie Intern Creat" << std::endl;
	this->tab[0] = new ShrubberyCreationForm();
	this->tab[1] = new RobotomyRequestForm();
	this->tab[2] = new PresidentialPardonForm();
}

Intern &Intern::operator=(const Intern& f)
{
	(void)f;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern Kill" << std::endl;
    delete tab[0];
    delete tab[1];
    delete tab[2];
}

AForm *Intern::makeForm(std::string form, std::string name)
{
	std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int i = 0;
	for(; forms[i] != form && i != 3; i++)
		;
	return i < 3 ? tab[i]->clone(name) : throw std::exception();
}
