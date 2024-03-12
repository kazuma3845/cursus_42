#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
	return ;
}

HumanA::HumanA( std::string name, Weapon& weapon ) : name(name), weapon(weapon)
{
	std::cout << this->name << " born" << std::endl;
	return ;
}

HumanA::~HumanA( void )
{
	std::cout << this->name << " died" << std::endl;
	return ;
}
