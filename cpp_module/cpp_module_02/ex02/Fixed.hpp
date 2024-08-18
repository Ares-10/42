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
	~Fixed();

	Fixed &operator=(const Fixed &f);
	bool operator>(const Fixed &f) const;
	bool operator<(const Fixed &f) const;
	bool operator>=(const Fixed &f) const;
	bool operator<=(const Fixed &f) const;
	bool operator==(const Fixed &f) const;
	bool operator!=(const Fixed &f) const;
	float operator+(const Fixed &f) const;
	float operator-(const Fixed &f) const;
	float operator*(const Fixed &f) const;
	float operator/(const Fixed &f) const;
	Fixed &operator++();
	Fixed &operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	float toFloat() const;
	int toInt() const;
	static const Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static const Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

	int getRawBits() const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif //FIXED_HPP
