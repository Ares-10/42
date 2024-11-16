#include <iostream>
#include "iter.hpp"

int main()
{
	int array[] = {0, 1, 2, 3, 4};
	std::string array2[] = {"a", "b", "c"};

	iter(array, 5, print);
	std::cout << std::endl;
	iter(array2, 5, print);
	std::cout << std::endl;
}
