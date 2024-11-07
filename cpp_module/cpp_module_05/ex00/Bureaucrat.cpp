#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	// std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name) : _name(name), _grade(150)
{
}

Bureaucrat::Bureaucrat(int grade) : _name("default")
{
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	// std::cout << "Default constructor called" << std::endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this == &src)
		return *this;
	this->_grade = src.getGrade();
	return *this;
}

const std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

void Bureaucrat::incrementGrade()
{
	setGrade(_grade - 1);
}

void Bureaucrat::decrementGrade()
{
	setGrade(_grade + 1);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << a->getName() << ", bureaucrat grade " << a->getGrade() << std::endl;
	return (o);
}
