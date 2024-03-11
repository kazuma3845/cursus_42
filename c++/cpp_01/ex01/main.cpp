#include "Zombie.hpp"

int main()
{
	Zombie z1("John");
	z1.announce();
	std::cout << std::endl;

	Zombie *z2 = zombieHorde(4, "Elton");
	for (int i = 0; i < 4; i++)
		z2[i].announce();
	delete[] z2;
	return (0);
}
