#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm", 145, 137),
																		_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): AForm("ShrubberyCreationForm", 145,
		137),
	_target(src._target)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this == &src)
		return *this;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	std::ofstream outfile(_target + "_shrubbery");
	outfile <<
			"         *" << std::endl <<
			"        ***" << std::endl <<
			"       *****" << std::endl <<
			"      *******" << std::endl <<
			"     *********" << std::endl <<
			"        ***" << std::endl <<
			"        ***" << std::endl;
	outfile.close();
}

std::string ShrubberyCreationForm::getTarget() const
{
	return _target;
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm *a)
{
	o << "Form " << a->getName() <<
			":\n\tsign-grade:\t" << a->getSignGrade() <<
			"\n\texec-grade:\t" << a->getExecGrade() <<
			"\n\tis signed:\t" << a->getIsSigned() <<
			std::endl;
	return (o);
}
