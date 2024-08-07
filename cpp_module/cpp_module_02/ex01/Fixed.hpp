#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int _raw_bits;
	static const int _ractional_bits;

public:
	Fixed();

	Fixed(const Fixed &f);

	Fixed(const int number);

	Fixed(const float number);

	Fixed &operator=(const Fixed &f);

	~Fixed();

	int getRawBits() const;

	void setRawBits(int const raw);

	float toFloat() const;

	int toInt() const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif //FIXED_HPP
