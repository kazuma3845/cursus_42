#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void) 
{
    Intern intern;
	std::cout << std::endl << std::endl;

    try 
	{
        AForm *SCF = intern.makeForm("ShrubberyCreationForm", "home");
        Bureaucrat b1("Bob", 136);
        Bureaucrat b2("Jhon", 145);
        b2.signForm(*SCF);
        b1.executeForm(*SCF);

        b2.executeForm(*SCF);
        delete SCF;
    }
	catch (std::exception &e) 
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }
	std::cout << std::endl << std::endl;

    try 
	{
        AForm *SCF = intern.makeForm("RobotomyRequestForm", "home");
        Bureaucrat b1("Bob2", 44);
        Bureaucrat b2("Jhon2", 72);
        b2.signForm(*SCF);
        b1.executeForm(*SCF);

        b2.executeForm(*SCF);
        delete SCF;
    }
    catch (std::exception &e) 
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }
	std::cout << std::endl << std::endl;

    try
	{
        AForm *SCF = intern.makeForm("PresidentialPardonForm", "home");
        Bureaucrat b1("Bob2", 5);
        Bureaucrat b2("Jhon2", 24);
        b2.signForm(*SCF);
        b1.executeForm(*SCF);

        b2.executeForm(*SCF);
        delete SCF;
    }
    catch (std::exception &e) 
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }
	std::cout << std::endl << std::endl;

    try 
	{
        AForm *SCF = intern.makeForm("None Existing Form", "home");
        Bureaucrat b1("Bob2", 5);
        Bureaucrat b2("Jhon2", 24);
        b2.signForm(*SCF);
        b1.executeForm(*SCF);

        b2.executeForm(*SCF);
        delete SCF;
    }
    catch (std::exception &e) 
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }
}
