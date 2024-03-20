#include "Form.hpp"

Form::Form(void) : _name(0), _Signed_grade(1), _Exec_grade(1), _Signed(false)
{
	if (this->_Signed_grade > 150)
		throw Form::GradeTooLowException();
	if (this->_Signed_grade < 1)
		throw Form::GradeTooHighException();
	std::cout << "Form " << this->_name << " Creat" << std::endl;
}

Form::Form(std::string name, int grade, int execGrade) : _name(name), _Signed_grade(grade), _Exec_grade(execGrade), _Signed(false)
{
	if (grade > 150)
		throw Form::GradeTooLowException();
	if (grade < 1)
		throw Form::GradeTooHighException();
	std::cout << "Form " << this->_name << " Creat" << std::endl;
}

Form::Form(const Form& f)  : _name(f._name), _Signed_grade(f._Signed_grade), _Exec_grade(f._Exec_grade), _Signed(false)
{
	if (f._Signed_grade > 150)
		throw Form::GradeTooLowException();
	if (f._Signed_grade < 1)
		throw Form::GradeTooHighException();
	std::cout << "Copie Form " << this->_name << " Creat" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form " << this->_name << " Destroy" << std::endl;
}

Form &Form::operator=(const Form& f)
{
	this->_Signed = f._Signed;
	return *this;
}

int Form::getExec_grade() const
{
	return this->_Exec_grade;
}

int Form::getSigned_grade() const
{
	return this->_Signed_grade;
}

std::string Form::getName() const
{
	return this->_name;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << f.getName();
	return os;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too High";
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too Low";
}

void Form::beSigned(Bureaucrat &f)
{
	if (f.getGrade() < this->_Signed_grade)
		this->_Signed = true;
	else
		this->_Signed = false;
}

bool Form::getSign()
{
	return this->_Signed;
}
