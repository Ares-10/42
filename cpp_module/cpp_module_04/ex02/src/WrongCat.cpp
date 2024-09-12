#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat : Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "WrongCat : Copy constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat : Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	std::cout << "WrongCat : Copy assignment operator called" << std::endl;
	_type = src._type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat : Meow!!" << std::endl;
}
