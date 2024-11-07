#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
private:
	const std::string _target;

	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

	void execute(Bureaucrat const &executor) const;
	std::string getTarget() const;
};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a);

#endif //SHRUBBERYCREATIONFORM_HPP
