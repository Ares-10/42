#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
private:
	std::string _ideas[100];

public:
	Brain();

	~Brain();

	Brain(const Brain &obj);

	Brain &operator=(const Brain &obj);

	const std::string *getIdeas() const;
};


#endif //BRAIN_HPP
