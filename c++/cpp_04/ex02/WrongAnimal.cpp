#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("No type")
{
	std::cout << "WrongAnimal Constructor called" << std::endl;	
}

WrongAnimal::WrongAnimal(const WrongAnimal& f)
{
	this->type = f.type;
	std::cout << "WrongAnimal Copie Constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& f)
{
	this->type = f.type;
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Destructor called" << std::endl;	
}

void WrongAnimal::makeSound() const
{
	std::cout << this->type << " say a indistinguishable sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return(type);
}
