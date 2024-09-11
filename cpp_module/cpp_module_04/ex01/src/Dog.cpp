#include "../include/Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain())
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
	delete _brain;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog : Copy assignment operator called" << std::endl;
	_type = src._type;
	_brain = new Brain(*src._brain);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << _type << " : Bark!!" << std::endl;
}
