#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) 
{
	this->_name = "";
	std::cout << "Default ShrubberyCreationForm Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm("ShrubberyCreationForm", 145, 137) 
{
	this->_name = name;
	std::cout << "ShrubberyCreationForm Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& f) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_name = f._name;
	std::cout << "Copie ShrubberyCreationForm Constructor Called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& f)
{
	this->_name = f._name;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor Called" << std::endl;
}

void ShrubberyCreationForm::action() const
{
	std::ofstream outfile(this->_name + "_shrubbery");
	if (!outfile)
	{
		std::cerr << "File don't creat" << std::endl;
		return ;
	}
	outfile << 
"          # #### ####\n"
"        ###'\'/#|### |/####\n"
"       ##'\'/#/ '\'||/##/_/##/_#\n"
"     ###  '\'/###|/ '\'/ # ###\n"
"   ##_'\'_#'\'_'\'## | #/###_/_####\n"
"  ## #### # '\' #| /  #### ##/##\n"
"   __#_--###`  |{,###---###-~\n"
"             '\' }{\n"
"              }}{]\n"
"              }}{\n"
"         ejm  {{}\n"
"        , -=-~{ .-^- _\n"
"              `}\n"
"               {\n"
	<< std::endl;
}

AForm *ShrubberyCreationForm::clone(std::string Target) 
{
    return new ShrubberyCreationForm(Target);
}
