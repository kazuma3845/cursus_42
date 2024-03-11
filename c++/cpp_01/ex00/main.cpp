#include "Zombie.hpp"

int main()
{
	Zombie z1("John");
	z1.announce();
	std::cout << std::endl;

	Zombie *z2 = newZombie("Eude");
	z2->announce();
	std::cout << std::endl;

	randomChump("Albert");
	std::cout << std::endl;

	delete(z2);
	return (0);
}
