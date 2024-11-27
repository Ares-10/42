#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return 0;
	}
	try
	{
		const RPN rpn = RPN(argv[1]);
		std::cout << rpn.getResult() << std::endl;
	} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
