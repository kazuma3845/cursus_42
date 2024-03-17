#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain Constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "";
}

Brain::Brain(const Brain& f)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = f.ideas[i];
	std::cout << "Brain Copie Constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain& f)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = f.ideas[i];
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor called" << std::endl;
}
