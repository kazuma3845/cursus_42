#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat Constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& f)
{
	this->type = f.type;
	std::cout << "Cat Copie Constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& f)
{
	this->type = f.type;
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
	delete this->brain;
}

void Cat::makeSound() const
{
	std::cout << this->type << " say: Miaou" << std::endl;
}

Brain *Cat::get_brain() const
{
	return this->brain;
}
