#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

// void f()
// {
// 	system("leaks Animal");
// }

int main()
{
	// atexit(f);

	// const Animal *a = new Animal();
	// delete a;
	const Animal *d = new Dog();
	const Animal *c = new Cat();

	delete d; //should not create a leak
	delete c;

	Dog dog1;
	Dog dog2 = dog1;

	std::cout << "\n";
	dog2.setType("TEST");
	dog1.makeSound();
	dog2.makeSound();

	std::cout << "\n\n\n";

	const Animal *animals[4];

	int i;
	for (i = 0; i < 2; i++)
	{
		animals[i] = new Cat();
		std::cout << "\n";
	}
	for (; i < 4; i++)
	{
		animals[i] = new Dog();
		std::cout << "\n";
	}
	for (i = 0; i < 4; i++)
	{
		delete animals[i];
		std::cout << "\n";
	}

	return 0;
}
