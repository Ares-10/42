#include "Span.hpp"

Span::Span() : _size(0), _index(0)
{
}

Span::Span(unsigned int n) : _size(n), _index(0)
{
}

Span::Span(Span const &copy)
{
	*this = copy;
}

Span::~Span()
{
}

Span &Span::operator=(Span const &src)
{
	if (this == &src)
		return *this;
	_size = src._size;
	_index = src._index;
	_stack = src._stack;
	return *this;
}

void Span::addNumber(int n)
{
	if (_index >= _size)
		throw std::exception();
	_stack.push_back(n);
	_index++;
}

int Span::shortestSpan()
{
	if (_index < 2)
		throw std::exception();

	int min = INT32_MAX;
	std::sort(_stack.begin(), _stack.end());
	for (unsigned int i = 0; i < _index - 1; i++)
		if (min > _stack[i + 1] - _stack[i])
			min = _stack[i + 1] - _stack[i];
	return min;
}

int Span::longestSpan()
{
	if (_index < 2)
		throw std::exception();
	std::sort(_stack.begin(), _stack.end());
	return _stack[_index - 1] - _stack[0];
}
