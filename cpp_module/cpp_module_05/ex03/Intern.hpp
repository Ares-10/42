#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
public:
	Intern();

	Intern(const Intern &copy);

	~Intern();

	Intern &operator=(const Intern &src);

	AForm *makeForm(const std::string &formName, const std::string &target);
};


#endif //INTERN_HPP
