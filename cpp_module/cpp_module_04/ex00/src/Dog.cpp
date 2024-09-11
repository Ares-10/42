#include "../include/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog : Default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog : Copy constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "Dog : Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog : Copy assignment operator called" << std::endl;
	_type = src._type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog : Bark!!" << std::endl;
}
