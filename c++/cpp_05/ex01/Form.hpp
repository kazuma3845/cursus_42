#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(std::string name, int grade, int execGrade);
		Form(const Form& f);
		Form &operator=(const Form& f);
		~Form(void);

		void beSigned(Bureaucrat &f);

		int getExec_grade() const;
		int getSigned_grade() const;
		std::string getName() const;
		bool getSign();

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
		const std::string _name;
		const int _Signed_grade;
		const int _Exec_grade;
		bool _Signed;

};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif