#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog Constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& f)
{
	this->type = f.type;
	std::cout << "Dog Copie Constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog& f)
{
	this->type = f.type;
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
	delete this->brain;
}

void Dog::makeSound() const
{
	std::cout << this->type << " say: Woof" << std::endl;
}

Brain *Dog::get_brain() const
{
	return this->brain;
}
