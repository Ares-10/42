#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"


class FragTrap : public ClapTrap
{
private:

public:
	FragTrap();

	FragTrap(const std::string &name);

	FragTrap(const FragTrap &copy);

	~FragTrap();

	FragTrap &operator=(const FragTrap &src);

	void highFivesGuys();
};


#endif //FRAGTRAP_HPP
