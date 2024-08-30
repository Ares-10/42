#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("tom");
	ClapTrap b("bob");
	ClapTrap c;

	c = a;

	a.attack("bob");
	b.takeDamage(15);
	c.beRepaired(4);

	b.takeDamage(3);
	b.beRepaired(3);
}
