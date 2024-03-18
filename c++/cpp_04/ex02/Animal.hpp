#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
	public:
		Animal(void);
		Animal(const Animal& f);
		Animal &operator=(const Animal& f);
		virtual ~Animal(void);
		virtual void makeSound() const = 0;
		virtual std::string getType() const;
		virtual Brain *get_brain() const;

	protected:
		std::string type;
};

#endif
