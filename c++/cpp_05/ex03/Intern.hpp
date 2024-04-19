#ifndef INTERN_HPP
# define INTERN_HPP

class Intern;

# include <iostream>
# include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern& f);
		Intern &operator=(const Intern& f);
		~Intern(void);

		AForm *makeForm(std::string form, std::string name);

	private:
		AForm *tab[3];
};

#endif