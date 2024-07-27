#include "Phonebook.hpp"

int main()
{
	Phonebook phonebook;
	std::string s;

	while (1)
	{
		std::cout << "[Phonebook]: ";
		std::getline(std::cin, s);
		if (s.compare("ADD") == 0)
			phonebook.add();
		else if (s.compare("SEARCH") == 0)
			phonebook.search();
		else if (s.compare("EXIT") == 0)
			exit(0);
	}
}
