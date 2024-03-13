#include "HumanB.hpp"
# include <string>

void HumanB::attack()
{
	if (this->weapon == NULL)
	{
		std::cout << this->name << " don't have weapon" << std::endl;
		return ;
	}
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	return ;
}

HumanB::HumanB( std::string name) : name(name)
{
	this->weapon = NULL;
	std::cout << this->name << " born" << std::endl;
	return ;
}

HumanB::~HumanB( void )
{
	std::cout << this->name << " died" << std::endl;
	return ;
}

void HumanB::setWeapon( Weapon& weapon )
{
	this->weapon = &weapon;
	std::cout << this->weapon->getType() << " add to " << this->name << std::endl;
	return ;
}
