#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& f);
		PresidentialPardonForm &operator=(const PresidentialPardonForm& f);
		~PresidentialPardonForm();
	private:

	
};

#endif