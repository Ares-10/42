#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();

	Cat(const Cat &copy);

	~Cat();

	Cat &operator=(const Cat &src);

	void makeSound() const;
};


#endif //CAT_HPP
