#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form(std::string name, int grade_signed, int grade_exec);
		Form( const Form& f );
		Form &operator=( const Form& f );
		~Form();

		std::string getName() const;
		int getGradeToSigned() const;
		int getGradeToExec() const;

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		void beSigned(const Bureaucrat &f);
		void signForm(const Bureaucrat &f);

	private:
		const std::string _name;
		bool _to_signed;
		const int _grade_to_signed;
		const int _grade_to_exec;
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif
