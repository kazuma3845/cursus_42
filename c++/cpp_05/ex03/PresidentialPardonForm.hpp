#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Intern.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& f);
		PresidentialPardonForm &operator=(const PresidentialPardonForm& f);
		~PresidentialPardonForm();

         AForm *clone(std::string Target);

		void action() const;

	private:
		std::string _target;
	
};

#endif