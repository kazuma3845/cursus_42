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
	if ((this->type == "Cat" || this->type == "Dog") && (f.type == "Cat" || f.type == "Dog"))
        *get_brain() = *f.get_brain();
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
	return(this->type);
}

Brain *Animal::get_brain() const
{
	return 0;
}
