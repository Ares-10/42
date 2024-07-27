#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook
{
private:
	Contact	_contacts[8];
	int		_index;

public:
	Phonebook();
	~Phonebook();

	void	add();
	void	search();
};

#endif
