#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : _garde_gate(false)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap : Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name), _garde_gate(false)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap : String constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy), _garde_gate(copy._garde_gate)
{
	std::cout << "ScavTrap : Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap : Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap : Copy assignment operator called" << std::endl;
	_name = src._name;
	_hit_points = src._hit_points;
	_energy_points = src._energy_points;
	_attack_damage = src._attack_damage;
	_garde_gate = src._garde_gate;
	return *this;
}


void ScavTrap::guardGate()
{
	if (_garde_gate == false)
	{
		_garde_gate = true;
		std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
	}
	else
		std::cout << "ScavTrap " << _name << " is already Gate keeper mode." << std::endl;
}
