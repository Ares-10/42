#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate()
{
	int i;

	i = rand() % 3;
	if (i == 0)
		return (new A);
	if (i == 1)
		return (new B);
	return (new C);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Class A: *p" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class B: *p" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class C: *p" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "Class A: &p" << std::endl;
		(void)a;
	} catch (std::bad_cast &e)
	{
		std::cout << "unknown" << std::endl;
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "Class B: &p" << std::endl;
		(void)b;
	} catch (std::bad_cast &e)
	{
		std::cout << "unknown" << std::endl;
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "Class C: &p" << std::endl;
		(void)c;
	} catch (std::bad_cast &e)
	{
		std::cout << "unknown" << std::endl;
	}
}

int main()
{
	std::cout << std::endl;

	srand(time(NULL));

	Base *base = generate();

	identify(base);
	identify(*base);

	std::cout << std::endl;

	delete base;
}
