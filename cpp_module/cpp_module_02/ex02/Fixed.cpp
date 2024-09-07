#include "Fixed.hpp"
#include <cmath>

const int Fixed::_ractional_bits = 8;

Fixed::Fixed() : _raw_bits(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int number) : _raw_bits(number)
{
	// std::cout << "Int constructor called" << std::endl;
	_raw_bits = number << _ractional_bits;
}

Fixed::Fixed(const float number)
{
	// std::cout << "Float constructor called" << std::endl;
	_raw_bits = roundf(number * 256);
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	_raw_bits = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return _raw_bits;
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	_raw_bits = raw;
}

int Fixed::toInt() const
{
	return _raw_bits >> _ractional_bits;
}

float Fixed::toFloat() const
{
	return (float) _raw_bits / 256;
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return o;
}

bool Fixed::operator>(const Fixed &f) const
{
	return getRawBits() > f.getRawBits();
}

bool Fixed::operator<(const Fixed &f) const
{
	return getRawBits() < f.getRawBits();
}

bool Fixed::operator>=(const Fixed &f) const
{
	return getRawBits() >= f.getRawBits();
}

bool Fixed::operator<=(const Fixed &f) const
{
	return getRawBits() <= f.getRawBits();
}

bool Fixed::operator==(const Fixed &f) const
{
	return getRawBits() == f.getRawBits();
}

bool Fixed::operator!=(const Fixed &f) const
{
	return getRawBits() != f.getRawBits();
}

float Fixed::operator+(const Fixed &f) const
{
	return toFloat() + f.toFloat();
}

float Fixed::operator-(const Fixed &f) const
{
	return toFloat() - f.toFloat();
}

float Fixed::operator*(const Fixed &f) const
{
	return toFloat() * f.toFloat();
}

float Fixed::operator/(const Fixed &f) const
{
	return toFloat() / f.toFloat();
}

Fixed &Fixed::operator++()
{
	_raw_bits += 1;
	return *this;
}

Fixed &Fixed::operator--()
{
	_raw_bits -= 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++*this;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--*this;
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (b < a)
		return b;
	return a;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (b < a)
		return b;
	return a;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (b > a)
		return b;
	return a;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (b > a)
		return b;
	return a;
}