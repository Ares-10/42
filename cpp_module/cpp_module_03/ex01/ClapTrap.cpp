#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap : Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap : String constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap : Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap : Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "ClapTrap : Copy assignment operator called" << std::endl;
	_name = src._name;
	_hit_points = src._hit_points;
	_energy_points = src._energy_points;
	_attack_damage = src._attack_damage;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hit_points <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't do anything, because its hit points is 0" << std::endl;
		return;
	}
	if (_energy_points <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't do anything, because its energy points is 0" << std::endl;
		return;
	}
	_energy_points--;
	std::cout << "ClapTrap " << _name << " attacks " << target
			<< ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points == 0)
	{
		std::cout << "ClapTrap " << _name << " can't take damage, because its already dead" << std::endl;
		return;
	}
	if (_hit_points < amount)
		_hit_points = 0;
	else
		_hit_points -= amount;
	std::cout << "ClapTrap " << _name << " took damage and lost " << amount << " hit points, "
			<< "so its now has " << _hit_points << " hit points " << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't do anything, because its hit points is 0" << std::endl;
		return;
	}
	if (_energy_points <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't do anything, because its energy points is 0" << std::endl;
		return;
	}
	_energy_points--;
	_hit_points += amount;
	std::cout << "ClapTrap " << _name << " is repaired and gained " << amount << " hit points, "
			<< "so its now has " << _hit_points << " hit points " << std::endl;
}
