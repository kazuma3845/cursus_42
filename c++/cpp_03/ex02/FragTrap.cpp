#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap Default Constructor called" << std::endl;
	this->_hit_point = 100;
	this->_energy_point = 100;
	this->_attack_dmg = 30;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Constructor called" << std::endl;
	this->_name = name;
	this->_hit_point = 100;
	this->_energy_point = 100;
	this->_attack_dmg = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &f) : ClapTrap()
{
	std::cout << "Copy Constructor called" << std::endl;
	this->_name = f._name;
	this->_hit_point = f._hit_point;
	this->_energy_point = f._energy_point;
	this->_attack_dmg = f._attack_dmg;
}

FragTrap& FragTrap::operator=(const FragTrap &f)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_name = f._name;
	this->_attack_dmg = f._attack_dmg;
	this->_hit_point = f._hit_point;
	this->_energy_point = f._energy_point;
	return *this;
}

void FragTrap::attack(const std::string& target)
{
	if (this->_hit_point <= 0)
		return ;
	if (this->_energy_point <= 0)
	{
		std::cout << this->_name << " don't have energy" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name;
	std::cout << " attacks " << target;
	std::cout << ", causing " << this->_attack_dmg << " points of damage !!!" << std::endl;
	std::cout << this->_name << " lose 1 energie point !!!" << std::endl;
	this->_energy_point--;
}

void FragTrap::takeDamage(unsigned int amount)
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

void FragTrap::beRepaired(unsigned int amount)
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

void FragTrap::highFivesGuys(void)
{
	if (this->_hit_point <= 0)
	{
		std::cout << this->_name << "is already dead !!!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " take is hand for high five !!!" << std::endl;
}
