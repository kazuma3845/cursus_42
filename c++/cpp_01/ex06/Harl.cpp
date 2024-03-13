#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl creat" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Harl destroy" << std::endl;
}

void Harl::complain( std::string level )
{
	std::string tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*Foncptr[4])(void);
	Foncptr[0] = &Harl::debug;
	Foncptr[1] = &Harl::info;
	Foncptr[2] = &Harl::warning;
	Foncptr[3] = &Harl::error;
	for (int i = 0; i < 4; i++)
	{
		if (tab[i].compare(level) == 0)
		{
			while (i < 4)
				(this->*Foncptr[i++])();
			return ;
		}
	}
	std::cout << "Bad level of Harl" << std::endl;
	return ;
}

void Harl::debug( void )
{
	std::cout << "DEBUG message" << std::endl;
}

void Harl::info( void )
{
	std::cout << "INFO message" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "WARNIG message" << std::endl;
}

void Harl::error( void )
{
	std::cout << "ERROR message" << std::endl;
}
