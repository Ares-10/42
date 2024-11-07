#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <fstream>
#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
private:
	const std::string _target;

	RobotomyRequestForm();
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm &src);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

	void execute(Bureaucrat const &executor) const;

	std::string getTarget() const;
};


std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a);

#endif //ROBOTOMYREQUESTFORM_HPP
