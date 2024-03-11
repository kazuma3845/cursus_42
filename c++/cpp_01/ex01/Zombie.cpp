#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : name(name)
{
	std::cout << "Zombie " << this->name << " creat" << std::endl;
	return ;
}

Zombie::Zombie( void )
{
	std::cout << "(default constructor)" << std::endl;
	return ;
}

Zombie::~Zombie( void )
{
	std::cout << "Zombie " << this->name << " destroy" << std::endl;
	return ;
}

void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void Zombie::setName(const std::string &newName)
{
	name = newName;
}
