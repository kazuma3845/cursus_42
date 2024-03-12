#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB( std::string name);
		~HumanB( void );
		void attack();
		void setWeapon( Weapon& wepon );
	private:
		std::string name;
		Weapon &weapon;
};

#endif
