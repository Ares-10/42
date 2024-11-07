#include "AForm.hpp"

AForm::AForm(): _name("default"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
}

AForm::AForm(const AForm &copy): _name(copy._name), _is_signed(false), _sign_grade(copy._sign_grade),
							_exec_grade(copy._exec_grade)
{
	*this = copy;
}

AForm::AForm(int sign_grade, int exec_grade): _name("default"), _is_signed(false), _sign_grade(sign_grade),
											_exec_grade(exec_grade)
{
	if (_sign_grade > 150 || _exec_grade > 150)
		throw GradeTooLowException();
	if (_sign_grade < 1 || _exec_grade < 1)
		throw GradeTooHighException();
}

AForm::AForm(const std::string &name): _name(name), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
}


AForm::AForm(const std::string &name, int sign_grade, int exec_grade): _name(name), _is_signed(false),
																	_sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (_sign_grade > 150 || _exec_grade > 150)
		throw GradeTooLowException();
	if (_sign_grade < 1 || _exec_grade < 1)
		throw GradeTooHighException();
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &src)
{
	if (this == &src)
		return *this;
	return *this;
}

void AForm::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() > _sign_grade)
		throw GradeTooLowException();
	_is_signed = true;
}

const std::string AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _is_signed;
}

int AForm::getSignGrade() const
{
	return _sign_grade;
}

int AForm::getExecGrade() const
{
	return _exec_grade;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form needs to be signed before executing");
};

std::ostream &operator<<(std::ostream &o, AForm *a)
{
	o << "AForm " << a->getName() << ":\n\tsign-grade:\t" << a->getSignGrade() <<
			"\n\texec-grade:\t" << a->getExecGrade() <<
			"\n\tis signed:\t" << a->getIsSigned() <<
			std::endl;
	return (o);
}
