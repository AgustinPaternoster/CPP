#include "PmergeMe.hpp"
#include <iostream>

int main(int arc, char** argv)
{
	if (arc < 3)
	{
		std::cout << "Error: At least 2 numbers are required." << std::endl;
		return(1);
	}
	try
	{
		FordJohnsonAlg::PmergeDeque deque;
		FordJohnsonAlg::PmergeVec	vec;
		deque.orderNumbers(argv);
		vec.orderNumbers(argv);
		vec.printSequence();
		deque.printTime();
		vec.printTime();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}	
	return (0);
}