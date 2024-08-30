#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap a("tom");
	FragTrap b;
	ClapTrap c;

	b = a;
	c = a;

	a.attack("bob");
	b.takeDamage(15);
	c.beRepaired(4);

	b.takeDamage(3);
	b.beRepaired(3);

	b.highFivesGuys();
}
