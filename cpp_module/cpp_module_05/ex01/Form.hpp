#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _is_signed;
	const int _sign_grade;
	const int _exec_grade;

public:
	Form();
	Form(const Form &copy);
	Form(int sign_grade, int exec_grade);
	Form(const std::string &name);
	Form(const std::string &name, int sign_grade, int exec_grade);
	~Form();

	Form &operator=(const Form &src);

	void beSigned(Bureaucrat &signer);

	const std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, Form *a);

#endif //FORM_HPP
