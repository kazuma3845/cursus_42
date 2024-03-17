#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& f);
		WrongAnimal &operator=(const WrongAnimal& f);
		~WrongAnimal(void);
		void makeSound() const;
		std::string getType() const;
	protected:
		std::string type;
};

#endif