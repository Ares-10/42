#include "Zombie.hpp"

int main()
{
	Zombie *horde;
	int N;

	N = 5;
	horde = zombieHorde(N, "Foo");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
}
