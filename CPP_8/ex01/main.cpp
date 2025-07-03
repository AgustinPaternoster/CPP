#include "Span.hpp"
#include "stdlib.h"

int main (void)
{
	Span sp(10);
	try
	{
	for (int i = 0; i < 2 ; i++)
		sp.addNumber(std::rand()% 100);	
	sp.printVec();
	std::cout << "Min: " << sp.shortestSpan() << std::endl;
	std::cout << "Max: " << sp.longestSpan() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);

}