#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : type(type)
{
	std::cout << this->type << "as creat" << std::endl;
	return ;
}

Weapon::~Weapon( void )
{
	std::cout << this->type << "as destroy" << std::endl;
	return ;
}

const std::string Weapon::getType()
{
	return(this->type);
}

void Weapon::setType( std::string newtype )
{
	this->type = newtype;
}

