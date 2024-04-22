#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try 
    {
        Form form1("Player Contract", 150, 150);
        Bureaucrat bCrat1("Richarlison", 1);
        bCrat1.signForm(form1);
        std::cout << "Welcome to the Club" << std::endl;
        bCrat1.IncrementGrade();
    }
    catch (std::exception &e) 
    {
        std::cout << "About to print the exception" << std::endl;
        std::cout << e.what() << std::endl;
    }
  
    std::cout  << std::endl << std::endl;
    try 
    {
        Form form1("Drivers License", 1, 1);
        std::cout << form1;
        Bureaucrat bCrat1("Caitlyn Jenner", 150);
        bCrat1.signForm(form1);
    }
    catch (std::exception &e) 
    {
        std::cout << "About to print the exception" << std::endl;
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << std::endl;
    Form form1;
    Form pContract("PlayerContract", 1, 1);
    Form pApplication("Passport Application", 150, 150);
    Form copyApplication(pApplication);
    
    std::cout << form1;
    form1 = pContract;
    std::cout << "Uknown Form should become a Player Contract now" << std::endl;
    std::cout << form1;
    std::cout << std::endl << std::endl;
    std::cout << copyApplication;
}
