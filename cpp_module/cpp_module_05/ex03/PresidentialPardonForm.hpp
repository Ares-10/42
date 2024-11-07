#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class AFrom;

class PresidentialPardonForm : public AForm
{
private:
	const std::string _target;

	PresidentialPardonForm();
public:
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(PresidentialPardonForm &src);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

	void execute(Bureaucrat const &executor) const;

	std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm *a);

#endif //PRESIDENTIALPARDONFORM_HPP
