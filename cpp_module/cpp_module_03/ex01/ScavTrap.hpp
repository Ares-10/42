#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"


class ScavTrap : public ClapTrap
{
private:
	bool _garde_gate;

public:
	ScavTrap();

	ScavTrap(const std::string &name);

	ScavTrap(const ScavTrap &copy);

	~ScavTrap();

	ScavTrap &operator=(const ScavTrap &src);

	void attack(const std::string &target);

	void guardGate();
};


#endif //SCAVTRAP_HPP
