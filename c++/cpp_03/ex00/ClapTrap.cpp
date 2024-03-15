#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _hit_point(10), _energy_point(10), _attack_dmg(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_point(10), _energy_point(10), _attack_dmg(0)
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &f) : _name(f._name)
{
	std::cout << "Copy Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = f._name;
	this->_attack_dmg = f._attack_dmg;
	this->_hit_point = f._hit_point;
	this->_energy_point = f._energy_point;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hit_point <= 0)
		return ;
	if (this->_energy_point <= 0)
	{
		std::cout << this->_name << " don't have energy" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name;
	std::cout << " attacks " << target;
	std::cout << ", causing " << this->_attack_dmg << " points of damage !!!" << std::endl;
	std::cout << this->_name << " lose 1 energie point !!!" << std::endl;
	this->_energy_point--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_point <= 0)
	{
		std::cout << this->_name << "is already dead !!!" << std::endl;
		return ;
	}
	std::cout << this->_name << " take " << amount << " damage on hit !!!" << std::endl;
	this->_hit_point -= amount;
	if (this->_hit_point <= 0)
		std::cout << this->_name << " is dead !!!" << std::endl;
	else
		std::cout << this->_name << " have " << this->_hit_point << " HP !!!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_point <= 0)
		return ;
	if (this->_energy_point <= 0)
	{
		std::cout << this->_name << " don't have energy" << std::endl;
		return ;
	}
	std::cout << this->_name << " regen " << amount << " of HP and lose 1 enrgie point !!!" << std::endl;
	this->_hit_point += amount;
	this->_energy_point--;
	std::cout << this->_name << " have " << this->_hit_point << " HP and ";
	std::cout << this->_energy_point << " energy point !!!" << std::endl;
}
