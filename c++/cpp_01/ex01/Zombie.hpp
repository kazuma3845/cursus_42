#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	public:
		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );
		void announce( void );

		void setName(const std::string &name);
	
	private:
		std::string name;

};

Zombie* zombieHorde( int N, std::string name );

#endif
