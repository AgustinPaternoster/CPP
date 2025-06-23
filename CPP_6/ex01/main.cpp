#include "Serializer.hpp"
#include <string>
#include <iostream>



int main(void)
{
	Data test;
	test.nb = 42;
	test.txt = "tester serial";

	uintptr_t a = Serializer::serialize(&test);
	std::cout  << "serialize pointer:" << a << std::endl;
	struct Data *ptr = Serializer::deserialize(a);
	std::cout << "deserialize: " << std::endl << *ptr << std::endl;
	return (0);
}