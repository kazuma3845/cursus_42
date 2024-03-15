#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	{
		FragTrap a("John");
		a.attack("Sephitoth");
		a.takeDamage(5);
		a.beRepaired(1);
		a.highFivesGuys();
	}
	std::cout << std::endl << std::endl;
	{
		FragTrap b("Warrior of light");
		for (int i = 0; i != 101; i++)
			b.attack("Emet Selch");
		b.takeDamage(9999999);
		b.beRepaired(1);
		b.attack("Emet Selch");
		b.takeDamage(9999999);
		b.highFivesGuys();
	}
	std::cout << std::endl << std::endl;
	{
		FragTrap c("Jean-Eude");
		c.beRepaired(500);
		c.takeDamage(509);
		c.attack("monster");
		c.highFivesGuys();
	}
	return 0;
}
