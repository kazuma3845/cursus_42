#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& f);
		RobotomyRequestForm &operator=(const RobotomyRequestForm& f);
		~RobotomyRequestForm();
	private:

	
};

#endif