#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
private:
	std::string _name;
	unsigned int _hit_points;
	unsigned int _energy_points;
	unsigned int _attack_damage;

	bool statusCheck() const;
public:
	ClapTrap();

	ClapTrap(const std::string &name);

	ClapTrap(const ClapTrap &copy);

	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &src);

	void attack(const std::string &target);

	void takeDamage(unsigned int amount);

	void beRepaired(unsigned int amount);
};

#endif //CLAPTRAP_HPP
