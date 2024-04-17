#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class Bureaucrat;

# include <iostream>
#include "AForm.hpp"

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& f);
		Bureaucrat &operator=(const Bureaucrat& f);
		~Bureaucrat(void);

		std::string getName() const;
		int getGrade() const;

		void IncrementGrade();
		void DecrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		void executeForm(AForm const &form);

	private:
		int _grade;
		std::string _name;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &f);

#endif