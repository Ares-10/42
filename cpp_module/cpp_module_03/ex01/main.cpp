#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("tom");
	ScavTrap b;
	ClapTrap c;

	b = a;
	c = a;

	a.attack("bob");
	b.takeDamage(15);
	c.beRepaired(4);

	b.takeDamage(3);
	b.beRepaired(3);

	b.guardGate();
	b.guardGate();
}
