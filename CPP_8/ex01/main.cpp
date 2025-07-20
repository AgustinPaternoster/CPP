#include "Span.hpp"
#include "stdlib.h"
#include "time.h"

int main (void)
{
	Span sp(4);
	// std::vector<int> add;
	// for (int i = 0; i < 5000 ; i++)
	// 	add.push_back(std::rand() % 1000000);
	// std::srand(time(NULL));	
	try
	{
	// for (int i = 0; i < 5000 ; i++)
	// 	sp.addNumber(std::rand()% 1000000);
	// for (int i = 0; i < 5000 ; i++)
	// 	sp.addNumber(std::rand()% 1000000);
	sp.addNumber(2);
	sp.addNumber(4);
	sp.addNumber(5);
	sp.addNumber(8);



	std::cout << "Min: " << sp.shortestSpan() << std::endl;
	std::cout << "Max: " << sp.longestSpan() << std::endl;
	// sp.addRange(add);
	// std::cout << "---------------" << std::endl;
	// std::cout << "Min: " << sp.shortestSpan() << std::endl;
	// std::cout << "Max: " << sp.longestSpan() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}