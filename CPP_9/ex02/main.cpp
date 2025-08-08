#include "PmergeMe.hpp"
#include <iostream>

int main(int arc, char** argv)
{
	(void)arc;
	try
	{
		PmergeMe test;
		test.orderNumbers(argv);
		test.print();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}	
	return (0);
}