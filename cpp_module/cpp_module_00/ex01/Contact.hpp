#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_secret;
public:
	Contact();
	~Contact();
	void	add();
	void	print_names();
	void	print_all();
	int		empty();
};

#endif
