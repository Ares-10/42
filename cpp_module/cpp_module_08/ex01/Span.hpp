#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>


class Span
{
private:
	std::vector<int>	_stack;
	unsigned int		_size;
	unsigned int		_index;

	Span();

public:
	Span(unsigned int n);
	Span(Span const &src);
	~Span();
	Span &operator=(Span const &obj);

	void	addNumber(int n);
	int		shortestSpan();
	int		longestSpan();
};


#endif //SPAN_HPP
