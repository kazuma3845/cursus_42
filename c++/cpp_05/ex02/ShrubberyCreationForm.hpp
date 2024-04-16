#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(const ShrubberyCreationForm& f);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm& f);
		~ShrubberyCreationForm();

		void action() const;

	private:
		std::string _name;
};

#endif