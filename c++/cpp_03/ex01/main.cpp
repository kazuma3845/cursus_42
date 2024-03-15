#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	{
		ScavTrap a("John");
		a.attack("Sephitoth");
		a.takeDamage(5);
		a.beRepaired(1);
		a.guardGate();
	}
	std::cout << std::endl << std::endl;
	{
		ScavTrap b("Warrior of light");
		for (int i = 0; i != 51; i++)
			b.attack("Emet Selch");
		b.takeDamage(9999999);
		b.beRepaired(1);
		b.attack("Emet Selch");
		b.takeDamage(9999999);
		b.guardGate();
	}
	std::cout << std::endl << std::endl;
	{
		ScavTrap c("Jean-Eude");
		c.beRepaired(500);
		c.takeDamage(509);
		c.attack("monster");
		c.guardGate();
	}
	return 0;
}
