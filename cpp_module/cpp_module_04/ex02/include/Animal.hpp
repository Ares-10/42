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
	virtual ~Animal() = 0;

	Animal &operator=(const Animal &src);

	std::string getType() const;
	void setType(const std::string &type);
	virtual void makeSound() const = 0;
};

#endif //ANIMAL_HPP
