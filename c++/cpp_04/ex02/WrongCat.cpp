#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat Constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& f)
{
	this->type = f.type;
	std::cout << "WrongCat Copie Constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& f)
{
	this->type = f.type;
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor called" << std::endl;	
}

void WrongCat::makeSound() const
{
	std::cout << this->type << " say: Miaou" << std::endl;
}
