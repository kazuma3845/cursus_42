#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = "";
	std::cout << "Default RobotomyRequestForm Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
	std::cout << "RobotomyRequestForm Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& f) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = f._target;
	std::cout << "Copie RobotomyRequestForm Constructor Called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& f)
{
	this->_target = f._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor Called" << std::endl;
}

void RobotomyRequestForm::action() const
{
	srand((long)this);
	if (rand() & 1)
	{	std::cout << "Bzzzzz" << std::endl << "Bzzzzz" << std::endl <<"Bzzzzz" << std::endl;
		std::cout << this->_target << " has been robotomized" << std::endl;
	}
	else
		std::cout << this->_target << " robotomized Failed" << std::endl;
}

AForm *RobotomyRequestForm::clone(std::string Target) 
{
    return new RobotomyRequestForm(Target);
}
