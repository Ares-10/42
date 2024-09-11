#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
protected:
	std::string _type;

public:
	Animal();

	Animal(const std::string &type);

	Animal(const Animal &copy);

	~Animal();

	Animal &operator=(const Animal &src);

	void makeSound() const;

	std::string getType() const;
};


#endif //ANIMAL_HPP
