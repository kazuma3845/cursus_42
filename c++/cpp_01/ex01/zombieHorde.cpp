#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde = new Zombie[N];
	for (int i = 0; i != N; i++)
	{
		std::string newname = name + std::to_string (i + 1);
		horde[i].setName(newname);
	}
	return horde;
}
