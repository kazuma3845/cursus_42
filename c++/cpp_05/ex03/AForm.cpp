#include "AForm.hpp"

AForm::AForm() : _name("Unknow"), _to_signed(false), _grade_to_signed(1), _grade_to_exec(1)
{
	std::cout << "Default AForm Constructor called" << std::endl;
}

AForm::AForm(std::string name, int grade_signed, int grade_exec) :  _name(name), _to_signed(false), _grade_to_signed(grade_signed), _grade_to_exec(grade_exec)
{
	std::cout << "AForm Constructor called" << std::endl;
}

AForm::AForm( const AForm &f ) : _name(f._name), _to_signed(false), _grade_to_signed(f._grade_to_signed), _grade_to_exec(f._grade_to_exec)
{
	std::cout << "Copy Default AForm Constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Default AForm Destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm& f)
{
	(void)f;
	return *this;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Form Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Form Grade too Low";
}

const char *AForm::GradeNoSignException::what() const throw()
{
	return "Form Grade not sign";
}

std::string AForm::getName() const
{
	return this->_name;
}

int AForm::getGradeToSigned() const
{
	return this->_grade_to_signed;
}

int AForm::getGradeToExec() const
{
	return this->_grade_to_exec;
}

void AForm::beSigned(const Bureaucrat &f)
{
	if (f.getGrade() <= this->getGradeToSigned())
		this->_to_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << f.getName() << " AForm Creat, Grade for signed : " << f.getGradeToSigned() << ", Grade to exec : " << f.getGradeToExec() << std::endl;
	return os;
}

void AForm::execute(const Bureaucrat &f) const
{
	try
	{
		if (f.getGrade() > this->getGradeToExec())
			throw GradeTooLowException();
		if (!this->getSigned())
			throw GradeNoSignException();
		this->action();
		std::cout << f.getName() << " executes " << this->getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Execution failed: " << e.what() << std::endl;
	}
}

bool AForm::getSigned() const
{
	return this->_to_signed;
}
