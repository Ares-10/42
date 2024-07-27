#include "Contact.hpp"

static void print_field(std::string s);

static bool empty_str(std::string s);

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::add()
{
	do
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, this->_first_name);
	} while (empty_str(this->_first_name));
	do
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, this->_last_name);
	} while (empty_str(this->_last_name));
	do
	{
		std::cout << "Enter nick name: ";
		std::getline(std::cin, this->_nickname);
	} while (empty_str(this->_nickname));
	do
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, this->_phone_number);
	} while (empty_str(this->_phone_number));
	do
	{
		std::cout << "Enter secret: ";
		std::getline(std::cin, this->_secret);
	} while (empty_str(this->_secret));
}

void Contact::print_names()
{
	print_field(this->_first_name);
	print_field(this->_last_name);
	print_field(this->_nickname);
	std::cout << std::endl;
}

int Contact::empty()
{
	if (this->_first_name.empty())
		return 1;
	return 0;
}

void Contact::print_all()
{
	std::cout << "first name: " << this->_first_name << std::endl;
	std::cout << "last name: " << this->_last_name << std::endl;
	std::cout << "nickname: " << this->_nickname << std::endl;
	std::cout << "phone number: " << this->_phone_number << std::endl;
	std::cout << "first name: " << this->_secret << std::endl;
}

bool empty_str(std::string s)
{
	for (unsigned long i = 0; i < s.length(); i++)
		if (!isspace(s[i]))
			return false;
	return true;
}

void print_field(std::string s)
{
	for (int i = 0; i < 10 - (int) s.length(); i++)
		std::cout << ' ';
	if (s.length() <= 10)
		std::cout << s << '|';
	else
	{
		for (int i = 0; i < 9; i++)
			std::cout << s[i];
		std::cout << ".|";
	}
}
