#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>

template <typename T>
int easyfind(T &t, int n)
{
	if (std::find(t.begin(), t.end(), n) == t.end())
		throw std::exception();
	return *std::find(t.begin(), t.end(), n);
}

#endif //EASYFIND_HPP
