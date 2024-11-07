#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45),
															_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src): AForm("RobotomyRequestForm", 72, 45),
																	_target(src._target)

{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this == &src)
		return *this;
	return *this;
}

static int robot_fail = 0;

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	std::cout << "* 드릴 위이잉 *" << std::endl;
	if (robot_fail++ % 2)
		std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << this->getTarget() << "." << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return _target;
}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm *a)
{
	o << "Form " << a->getName() <<
			":\n\tsign-grade:\t" << a->getSignGrade() <<
			"\n\texec-grade:\t" << a->getExecGrade() <<
			"\n\tis signed:\t" << a->getIsSigned() <<
			std::endl;
	return (o);
}
