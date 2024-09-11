#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
protected:
	std::string _type;

public:
	WrongAnimal();

	WrongAnimal(const std::string &type);

	WrongAnimal(const WrongAnimal &copy);

	~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &src);

	void makeSound() const;

	std::string getType() const;
};


#endif //WRONGANIMAL_HPP
