#include "Form.hpp"

Form::Form(): _name("default"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
}

Form::Form(const Form &copy): _name(copy._name), _is_signed(false), _sign_grade(copy._sign_grade),
							_exec_grade(copy._exec_grade)
{
	*this = copy;
}

Form::Form(int sign_grade, int exec_grade): _name("default"), _is_signed(false), _sign_grade(sign_grade),
											_exec_grade(exec_grade)
{
	if (_sign_grade > 150 || _exec_grade > 150)
		throw GradeTooLowException();
	if (_sign_grade < 1 || _exec_grade < 1)
		throw GradeTooHighException();
}

Form::Form(const std::string &name): _name(name), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
}


Form::Form(const std::string &name, int sign_grade, int exec_grade): _name(name), _is_signed(false),
																	_sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (_sign_grade > 150 || _exec_grade > 150)
		throw GradeTooLowException();
	if (_sign_grade < 1 || _exec_grade < 1)
		throw GradeTooHighException();
}

Form::~Form()
{
}

Form &Form::operator=(const Form &src)
{
	std::cout << "Form Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

void Form::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() > _sign_grade)
		throw GradeTooLowException();
	_is_signed = true;
}

const std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _is_signed;
}

int Form::getSignGrade() const
{
	return _sign_grade;
}

int Form::getExecGrade() const
{
	return _exec_grade;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

std::ostream &operator<<(std::ostream &o, Form *a)
{
	o << "Form " << a->getName() << ":\n\tsign-grade:\t" << a->getSignGrade() <<
			"\n\texec-grade:\t" << a->getExecGrade() <<
			"\n\tis signed:\t" << a->getIsSigned() <<
			std::endl;
	return (o);
}
