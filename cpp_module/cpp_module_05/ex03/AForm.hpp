#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
protected:
	const std::string _name;
	bool _is_signed;
	const int _sign_grade;
	const int _exec_grade;

public:
	AForm();

	AForm(const AForm &copy);

	AForm(int sign_grade, int exec_grade);

	AForm(const std::string &name);

	AForm(const std::string &name, int sign_grade, int exec_grade);

	virtual ~AForm();

	AForm &operator=(const AForm &src);

	void beSigned(Bureaucrat &signer);

	virtual void execute(Bureaucrat const &executor) const = 0;

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

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, AForm *a);

#endif //AFORM_HPP
