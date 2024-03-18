#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& f);
		Bureaucrat &operator=(const Bureaucrat& f);
		~Bureaucrat(void);

	private:
		int grade;
		std::string name;
};

#endif