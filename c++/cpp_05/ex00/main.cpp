#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a = Bureaucrat("John", 50);
		std::cout << a << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Grade too high" << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Grade too Low" << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat b = Bureaucrat("Elton", 150);
		std::cout << b << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Grade too high" << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Grade too Low" << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat c = Bureaucrat("Pierre", 151);
		std::cout << c << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Grade too high" << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Grade too Low" << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat d = Bureaucrat("Eude", 1);
		std::cout << d << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Grade too high" << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Grade too Low" << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat e = Bureaucrat("Stalone", 0);
		std::cout << e << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Grade too high" << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Grade too Low" << std::endl;
	}
	return 0;
}
