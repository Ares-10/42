#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter {
	ScalarConverter();
public:
	ScalarConverter(const ScalarConverter &copy);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &src);

	static void convert(std::string str);
};

int hasNonDisplayableChar(std::string str);

#endif //SCALARCONVERTER_HPP
