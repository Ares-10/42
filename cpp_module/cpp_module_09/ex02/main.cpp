#include "PmergeMe.hpp"
#include <sstream>

static void err()
{
	std::cerr << "Error" << std::endl;
	exit(1);
}

static void checkPositiveInteger(std::string s)
{
	for (int i = 0; s[i]; i++)
		if (!std::isdigit(s[0]))
			err();
	if (s[0] == '0')
		err();
	if (static_cast<long>(strtod(s.c_str(), NULL) > INT32_MAX))
		err();
}

int main(int argc, char **argv)
{
	if (argc < 2)
		err();
	std::vector<int> input;
	for (int i = 1; i < argc; i++)
	{
		std::string str(argv[i]);
		checkPositiveInteger(str);
		input.push_back(static_cast<int>(strtod(str.c_str(), NULL)));
	}
	PmergeMe pmerge_me = PmergeMe(input);
	pmerge_me.sort();
	pmerge_me.printResult();
}
