#include "RPN.hpp"

RPN::RPN() : _result(0)
{
}

RPN::RPN(RPN const &src) : _result(src._result)
{
	*this = src;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(RPN const &src)
{
	if (this == &src)
		return *this;
	_stack = src._stack;
	return *this;
}

static void checkValidExpression(const std::string &expression)
{
	if (expression.size() % 2 != 1)
		throw std::runtime_error("Error");
	for (size_t i = 0; i < expression.size(); i += 2)
	{
		if (!std::isdigit(expression[i]) &&
			!(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/'))
			throw std::runtime_error("Error");
		if (expression[i + 1] != ' ' && expression[i + 1] != '\0')
			throw std::runtime_error("Error");
	}
}

RPN::RPN(const std::string &expression) : _result(0)
{
	int	n;

	checkValidExpression(expression);
	for (size_t i = 0; i < expression.size(); i += 2)
	{
		if (std::isdigit(expression[i]))
			_stack.push(expression[i] - '0');
		else
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error");
			n = _stack.top();
			_stack.pop();
			if (expression[i] == '+')
				n = _stack.top() + n;
			else if (expression[i] == '-')
				n = _stack.top() - n;
			else if (expression[i] == '*')
				n = _stack.top() * n;
			else if (expression[i] == '/')
				n = _stack.top() / n;
			_stack.pop();
			_stack.push(n);
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error");
	_result = _stack.top();
}

int RPN::getResult() const
{
	return _result;
}
