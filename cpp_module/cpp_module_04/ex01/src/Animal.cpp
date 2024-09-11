#include "../include/Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal : Default constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type)
{
	std::cout << "Animal : String constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal : Copy constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal : Destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Animal : Copy assignment operator called" << std::endl;
	_type = src._type;
	return *this;
}

void Animal::makeSound() const
{
	if (_type.empty())
		std::cout << "Animal : Type not defined" << std::endl;
	else
		std::cout << "Animal : makeSound() called" << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}

void Animal::setType(const std::string &type)
{
	_type = type;
}