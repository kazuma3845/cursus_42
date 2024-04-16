#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& f);
		RobotomyRequestForm &operator=(const RobotomyRequestForm& f);
		~RobotomyRequestForm();

		void action() const;
	private:
		std::string _target;
	
};

#endif