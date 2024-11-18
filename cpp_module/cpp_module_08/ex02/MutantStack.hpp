#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>()
	{
	}

	MutantStack(MutantStack const &src)
	{
		*this = src;
	}

	~MutantStack()
	{
	}

	MutantStack &operator=(MutantStack const &src)
	{
		if (this != &src)
			this->c = src.c;
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin()
	{
		return std::stack<T>::c.begin();
	}

	iterator end()
	{
		return std::stack<T>::c.end();
	}
};

#endif //MUTANTSTACK_HPP
