#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *_brain;

public:
	Cat();

	Cat(const Cat &copy);

	~Cat();

	Cat &operator=(const Cat &src);

	void makeSound() const;
};


#endif //CAT_HPP
