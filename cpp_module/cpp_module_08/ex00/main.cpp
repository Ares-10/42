#include <vector>
#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);

	std::cout << easyfind(v, 3) << std::endl;
	try
	{
		std::cout << easyfind(v, 4) << std::endl;
	} catch (std::exception &e)
	{
		std::cout << "not exist" << std::endl;
	}
}
