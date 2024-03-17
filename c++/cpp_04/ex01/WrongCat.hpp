#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat& f);
		WrongCat &operator=(const WrongCat& f);
		~WrongCat(void);
		void makeSound() const;
};

#endif