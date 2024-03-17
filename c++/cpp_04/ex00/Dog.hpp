#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog& f);
		Dog &operator=(const Dog& f);
		virtual ~Dog(void);
		virtual void makeSound() const;
};

#endif