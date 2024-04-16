#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& f);
		PresidentialPardonForm &operator=(const PresidentialPardonForm& f);
		~PresidentialPardonForm();

		void action() const;

	private:
		std::string _target;
	
};

#endif