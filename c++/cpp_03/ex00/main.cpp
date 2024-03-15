#include "ClapTrap.hpp"

int main()
{
	{
		ClapTrap a("John");
		a.attack("Sephitoth");
		a.takeDamage(5);
		a.beRepaired(1);
	}
	std::cout << std::endl << std::endl;
	{
		ClapTrap b("Warrior of light");
		b.attack("Emet Selch");
		b.attack("Emet Selch");
		b.attack("Emet Selch");
		b.attack("Emet Selch");
		b.attack("Emet Selch");
		b.attack("Emet Selch");
		b.attack("Emet Selch");
		b.attack("Emet Selch");
		b.attack("Emet Selch");
		b.attack("Emet Selch");
		b.attack("Emet Selch");
		b.takeDamage(9999999);
		b.beRepaired(1);
		b.attack("Emet Selch");
		b.takeDamage(9999999);
	}
	std::cout << std::endl << std::endl;
	{
		ClapTrap c("Jean-Eude");
		c.beRepaired(500);
		c.takeDamage(509);
		c.attack("monster");
	}
	return 0;
}
