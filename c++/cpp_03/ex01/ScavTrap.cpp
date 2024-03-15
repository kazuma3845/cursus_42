#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_dmg = 20;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Constructor called" << std::endl;
	this->_name = name;
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_dmg = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &f) : ClapTrap()
{
	std::cout << "Copy Constructor called" << std::endl;
	this->_name = f._name;
	this->_hit_point = f._hit_point;
	this->_energy_point = f._energy_point;
	this->_attack_dmg = f._attack_dmg;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &f)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_name = f._name;
	this->_attack_dmg = f._attack_dmg;
	this->_hit_point = f._hit_point;
	this->_energy_point = f._energy_point;
	return *this;
}

void ScavTrap::guardGate()
{
	if (this->_hit_point <= 0)
	{
		std::cout << this->_name << "is already dead !!!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}


void ScavTrap::attack(const std::string& target)
{
	if (this->_hit_point <= 0)
		return ;
	if (this->_energy_point <= 0)
	{
		std::cout << this->_name << " don't have energy" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name;
	std::cout << " attacks " << target;
	std::cout << ", causing " << this->_attack_dmg << " points of damage !!!" << std::endl;
	std::cout << this->_name << " lose 1 energie point !!!" << std::endl;
	this->_energy_point--;
}

void ScavTrap::takeDamage(unsigned int amount)
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

void ScavTrap::beRepaired(unsigned int amount)
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
