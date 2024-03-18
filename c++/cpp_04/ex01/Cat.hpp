#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat& f);
		Cat &operator=(const Cat& f);
		~Cat(void);
		void makeSound() const;
		Brain *get_brain() const;
	private:
		Brain *brain;
};

#endif