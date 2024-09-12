#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal : Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type)
{
	std::cout << "WrongAnimal : String constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal : Copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal : Destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "WrongAnimal : Copy assignment operator called" << std::endl;
	_type = src._type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	if (_type.empty())
		std::cout << "WrongAnimal : Type not defined" << std::endl;
	else
		std::cout << "WrongAnimal : makeSound() called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return _type;
}