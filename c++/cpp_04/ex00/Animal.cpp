#include "Animal.hpp"
#include "Dog.hpp"

Animal::Animal(void) : type("No type")
{
	std::cout << "Animal Constructor called" << std::endl;	
}

Animal::Animal(const Animal& f)
{
	this->type = f.type;
	std::cout << "Animal Copie Constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal& f)
{
	this->type = f.type;
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal Destructor called" << std::endl;	
}

void Animal::makeSound() const
{
	std::cout << this->type << " say a indistinguishable sound" << std::endl;
}

std::string Animal::getType() const
{
	return(type);
}
