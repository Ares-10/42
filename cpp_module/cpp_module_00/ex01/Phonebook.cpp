#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	this->_index = 0;
}

Phonebook::~Phonebook()
{
}

void Phonebook::add()
{
	this->_contacts[this->_index].add();
	this->_index++;
	if (this->_index == 8)
		this->_index = 0;
}

void Phonebook::search()
{
	std::string str;

	if (this->_contacts[0].empty())
	{
		std::cout << "Phonebook is empty!" << std::endl;
		return;
	}
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < 8 && !this->_contacts[i].empty(); i++)
	{
		std::cout << "|         " << i << '|';
		this->_contacts[i].print_names();
	}
	std::cout << "[Phonebook] enter index: ";
	std::getline(std::cin, str);
	if (str.size() == 1 && str[0] >= '0' && str[0] < '8' && !this->_contacts[str[0] - '0'].empty())
		this->_contacts[str[0] - '0'].print_all();
	else
		std::cout << "Error: invalid indexes" << std::endl;
}
