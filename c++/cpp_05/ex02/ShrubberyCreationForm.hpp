#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& f);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm& f);
		~ShrubberyCreationForm();

	private:

};

#endif