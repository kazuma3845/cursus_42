#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat a = Bureaucrat("John", 50);
		Form form = Form("Contract", 40, 1);
		form.beSigned(a);
		a.signForm(form);
		std::cout << a << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
