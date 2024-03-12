#include "HumanB.hpp"

void HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon << std::endl;
	return ;
}

HumanA::HumanB( std::string name) : name(name) 
{
	std::cout << this->name << " born" << std::endl;
	return ;
}

HumanA::~HumanB( void )
{
	std::cout << this->name << " died" << std::endl;
	return ;
}

void HumanB::setWeapon( Weapon& weapon ) : weapon(weapon)
{
	std::cout << this->weapon << " add to " << this->name << std::endl;
	return ;
}
