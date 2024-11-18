#include <iostream>
#include "Span.hpp"

int main()
{ {
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} {
		Span sp = Span(5 * 10000);
		for (int i = 0; i < 10000; i++)
		{
			sp.addNumber(5 * (i + 1));
			sp.addNumber(3 * (i + 1));
			sp.addNumber(20 * (i + 1));
			sp.addNumber(9 * (i + 1));
			sp.addNumber(11 * (i + 1));
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
}
