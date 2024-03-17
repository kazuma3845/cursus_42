#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat& f);
		Cat &operator=(const Cat& f);
		virtual ~Cat(void);
		virtual void makeSound() const;
};

#endif