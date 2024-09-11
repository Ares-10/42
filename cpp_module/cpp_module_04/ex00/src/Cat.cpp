#include "../include/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat : Default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat : Copy constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "Cat : Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat : Copy assignment operator called" << std::endl;
	_type = src._type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat : Meow!!" << std::endl;
}
