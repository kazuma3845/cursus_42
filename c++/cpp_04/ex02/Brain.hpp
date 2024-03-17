#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain& f);
		Brain &operator=(const Brain& f);
		~Brain(void);

		std::string ideas[100];
};

#endif