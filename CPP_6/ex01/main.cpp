#include "Serializer.hpp"
#include <string>
#include <iostream>



int main(void)
{
	Data test;
	test.nb = 42;
	test.txt = "tester serial";
	try
	{
		uintptr_t a = Serializer::serialize(&test);
		std::cout  << "serialize pointer:" << a << std::endl;
		struct Data *ptr = Serializer::deserialize(a);
		std::cout << "deserialize: " << std::endl << *ptr << std::endl;
	}
	catch(const char * msg)
	{
		std::cerr << msg << '\n';
	}
	
	return (0);
}