#include <iostream>

#include "Template.hpp"

int main()
{
	// 정수형 테스트
	int a = 10, b = 20;
	std::cout << "=== Integer Test ===" << std::endl;
	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
	std::cout << "min: " << min(a, b) << std::endl;
	std::cout << "max: " << max(a, b) << std::endl;

	// 실수형 테스트
	double x = 3.14, y = 2.718;
	std::cout << "\n=== Double Test ===" << std::endl;
	std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
	swap(x, y);
	std::cout << "After swap: x = " << x << ", y = " << y << std::endl;
	std::cout << "min: " << min(x, y) << std::endl;
	std::cout << "max: " << max(x, y) << std::endl;
}