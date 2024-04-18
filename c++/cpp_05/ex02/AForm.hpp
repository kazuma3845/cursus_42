#ifndef AFORM_HPP
# define AFORM_HPP

class AForm;

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm();
		AForm(std::string name, int grade_signed, int grade_exec);
		AForm( const AForm& f );
		AForm &operator=( const AForm& f );
		virtual ~AForm();

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

		bool getSigned() const;

		void execute(Bureaucrat const & executor) const;
		virtual void action() const = 0;

	private:
		const std::string _name;
		bool _to_signed;
		const int _grade_to_signed;
		const int _grade_to_exec;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif
