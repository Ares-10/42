#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &src)
{
	if (this == &src)
		return *this;
	return *this;
}

static AForm *makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	AForm *(*all_forms[])(std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			std::cout << "Intern creates " << formName << " now" << std::endl;
			return all_forms[i](target);
		}
	}

	std::cout << "Intern can not create a form called " << formName << std::endl;
	return (NULL);
}
