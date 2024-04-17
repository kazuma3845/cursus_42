#include "AForm.hpp"

AForm::AForm() : _name(NULL), _to_signed(false), _grade_to_signed(1), _grade_to_exec(1)
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
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too Low";
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
	else if (this->getGradeToSigned() <= 0)
		std::cout << "Grade too High" << std::endl;
	else
		std::cout << "Grade too Low" << std::endl;
}
void AForm::signForm(const Bureaucrat &f)
{
	if (this->_to_signed)
		std::cout << f.getName() << " signed " << this->getName() << std::endl;
	else if (this->getGradeToSigned() <= 0)
		std::cout << f.getName() << " couldn't sign " << this->getName() << " because grade too High" << std::endl;
	else
		std::cout << f.getName() << " couldn't sign " << this->getName() << " because grade too Low" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << f.getName() << " AForm Creat, Grade for signed : " << f.getGradeToSigned() << ", Grade to exec : " << f.getGradeToExec() << std::endl;
	return os;
}

void AForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() > this->getGradeToExec()) {
			throw GradeTooLowException();
		}
		std::cout << executor.getName() << " executes " << this->getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Execution failed: " << e.what() << std::endl;
	}
}
