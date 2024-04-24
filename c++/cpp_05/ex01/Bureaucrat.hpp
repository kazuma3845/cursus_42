#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class Bureaucrat;

# include <iostream>
#include "Form.hpp"

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

		void signForm(Form &f);

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

	private:
		int _grade;
		const std::string _name;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &f);

#endif