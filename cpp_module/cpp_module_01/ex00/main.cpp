#include "Zombie.hpp"

void f()
{
	system("leaks Zombie");
}

int main()
{
	Zombie *zombie1;
	Zombie *zombie2;
	Zombie *zombie3;

	randomChump("Stack Zombie 1");
	randomChump("Stack Zombie 2");
	randomChump("Stack Zombie 3");

	zombie1 = newZombie("Heap Zombie 1");
	zombie2 = newZombie("Heap Zombie 2");
	zombie3 = newZombie("Heap Zombie 3");

	zombie1->announce();
	zombie2->announce();
	zombie3->announce();

	delete zombie1;
	delete zombie2;
	delete zombie3;
}
