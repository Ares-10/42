#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int _raw_bits;
	static const int _ractional_bits = 8;

public:
	Fixed();

	Fixed(const Fixed &f);

	Fixed &operator=(const Fixed &f);

	~Fixed();

	int getRawBits() const;

	void setRawBits(int const raw);
};

#endif //FIXED_HPP
