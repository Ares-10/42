#include <iostream>
#include "Serializer.hpp"

// void f()
// {
// 	system("leaks serializer");
// }

int main()
{
	// atexit(f);

	Data* ptr = new Data;
	ptr->str = "42seoul";
	ptr->n = 42;
	ptr->b = true;
	ptr->d = 42.42;

	uintptr_t raw = Serializer::serialize(ptr);
	Data* new_ptr = Serializer::deserialize(raw);

	std::cout << "원본: " << ptr->str << ", " << ptr->n << ", " << ptr->b << ", " << ptr->d << std::endl;
	std::cout << "변환: " << new_ptr->str << ", " << new_ptr->n << ", " << new_ptr->b << ", " << new_ptr->d << std::endl;

	delete ptr;
}