#include "Form.hpp"

Form::Form() : _name(NULL), _to_signed(false), _grade_to_signed(1), _grade_to_exec(1)
{
	std::cout << "Default Form Constructor called" << std::endl;
}

Form::Form(std::string name, int grade_signed, int grade_exec) :  _name(name), _to_signed(false), _grade_to_signed(grade_signed), _grade_to_exec(grade_exec)
{
	std::cout << "Form Constructor called" << std::endl;
}

Form::Form( const Form &f ) : _name(f._name), _to_signed(false), _grade_to_signed(f._grade_to_signed), _grade_to_exec(f._grade_to_exec)
{
	std::cout << "Copy Default Form Constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Default Form Destructor called" << std::endl;
}

Form &Form::operator=(const Form& f)
{
	(void)f;
	return *this;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too Low";
}

std::string Form::getName() const
{
	return this->_name;
}

int Form::getGradeToSigned() const
{
	return this->_grade_to_signed;
}

int Form::getGradeToExec() const
{
	return this->_grade_to_exec;
}

void Form::beSigned(const Bureaucrat &f)
{
	if (f.getGrade() <= this->getGradeToSigned())
		this->_to_signed = true;
	else if (this->getGradeToSigned() <= 0)
		std::cout << "Grade too High" << std::endl;
	else
		std::cout << "Grade too Low" << std::endl;
}
void Form::signForm(const Bureaucrat &f)
{
	if (this->_to_signed)
		std::cout << f.getName() << " signed " << this->getName() << std::endl;
	else if (this->getGradeToSigned() <= 0)
		std::cout << f.getName() << " couldn't sign " << this->getName() << " because grade too High" << std::endl;
	else
		std::cout << f.getName() << " couldn't sign " << this->getName() << " because grade too Low" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << f.getName() << " Form Creat, Grade for signed : " << f.getGradeToSigned() << ", Grade to exec : " << f.getGradeToExec() << std::endl;
	return os;
}

void Form::execForm(const Bureaucrat &f)
{
	if (f.getGrade() <= this->getGradeToExec() && this->_to_signed)
		std::cout << f.getName() << " execute " << this->getName() << std::endl;
	else if (this->getGradeToExec() <= 0)
		std::cout << f.getName() << " couldn't execute " << this->getName() << " because grade too High" << std::endl;
	else
		std::cout << f.getName() << " couldn't execute " << this->getName() << " because grade too Low" << std::endl;
}
