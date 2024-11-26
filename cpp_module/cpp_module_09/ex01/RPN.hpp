#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
private:
	std::stack<int>	_stack;
	int				_result;

	RPN();

public:
	RPN(const std::string &expression);
	RPN(RPN const &src);
	~RPN();
	RPN &operator=(RPN const &src);

	int getResult() const;
};



#endif //RPN_HPP
