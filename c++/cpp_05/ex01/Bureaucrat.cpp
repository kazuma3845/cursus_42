#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) :  _grade(150), _name(0)
{
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Bureaucrat " << this->_name << " Creat" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _grade(grade), _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Bureaucrat " << this->_name << " Creat" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& f)  : _grade(f._grade), _name(f._name)
{
	if (f._grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (f._grade < 1)
		throw Bureaucrat::GradeTooHighException();
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
	return "Grade too High";
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too Low";
}

void Bureaucrat::IncrementGrade()
{
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::DecrementGrade()
{
	this->_grade++;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::signForm(const Form &f)
{
	if (f.getSigned())
		std::cout << f.getName() << " signed " << this->getName() << std::endl;
	else if (f.getGradeToSigned() <= 0)
		std::cout << f.getName() << " couldn't sign " << this->getName() << " because grade too High" << std::endl;
	else
		std::cout << f.getName() << " couldn't sign " << this->getName() << " because grade too Low" << std::endl;
}
