#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog& f);
		Dog &operator=(const Dog& f);
		~Dog(void);
		void makeSound() const;
		Brain *get_brain() const;
	private:
		Brain* brain;
};

#endif