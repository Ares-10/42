#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();

	WrongCat(const WrongCat &copy);

	~WrongCat();

	WrongCat &operator=(const WrongCat &src);

	void makeSound() const;
};



#endif //WRONGCAT_HPP
