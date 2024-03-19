#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) :  _grade(0), _name(0)
{
	std::cout << "Bureaucrat " << this->_name << " Creat" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _grade(grade), _name(name)
{
	std::cout << "Bureaucrat " << this->_name << " Creat" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& f)  : _grade(f._grade), _name(f._name)
{
	std::cout << "Copie Bureaucrat " << this->_name << " Creat" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << this->_name << " Destroy" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& f)
{
	this->_grade = f._grade;
	this->_name = f._name;
	return *this;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &f)
{
	os << f.getName() << ", bureaucrat grade " << f.getGrade();
	return os;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "TooLowException";
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "TooHighException";
}
