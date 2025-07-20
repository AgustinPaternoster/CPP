#include "Span.hpp"
#include "stdlib.h"
#include "time.h"

int main (int arc, char **argv)
{
	if (arc > 1)
	{
		Span sp(arc - 1);
		try
		{
			for (int i = 1; i < arc; i++)
				sp.addNumber(std::atoi(argv[i]));
			std::cout << "Min: " << sp.shortestSpan() << std::endl;
			std::cout << "Max: " << sp.longestSpan() << std::endl;
		}	
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		return (0);
	}
	else
	{
		Span sp(9);
		std::vector<int> add;
		for (int i = 0; i < 10 ; i++)
			add.push_back(std::rand() % 1000);
		std::srand(time(NULL));	
		try
		{
		// for (int i = 0; i < 10 ; i++)
		// 	sp.addNumber(std::rand()% 1000);
		// std::cout << "Min: " << sp.shortestSpan() << std::endl;
		// std::cout << "Max: " << sp.longestSpan() << std::endl;
		sp.addRange(add.begin(), add.end());
		std::cout << "---------------" << std::endl;
		std::cout << "Min: " << sp.shortestSpan() << std::endl;
		std::cout << "Max: " << sp.longestSpan() << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		return (0);
	}
}