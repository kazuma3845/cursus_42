#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(const Animal& f);
		Animal &operator=(const Animal& f);
		virtual ~Animal(void);
		virtual void makeSound() const;
		std::string getType() const;
	protected:
		std::string type;
};

#endif
