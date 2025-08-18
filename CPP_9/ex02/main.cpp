#include "PmergeMe.hpp"
#include <iostream>

int main(int arc, char** argv)
{
	(void)arc;
	try
	{
		FordJohnsonAlg::PmergeVec test;
		test.orderNumbers(argv);
		test.printSequence();
		test.printTime();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}	
	return (0);
}