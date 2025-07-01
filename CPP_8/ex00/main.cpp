#include <iostream>
#include <vector>
#include "easyfind.hpp"
#include <stdlib.h>
#include <ctime>

int main(void)
{
	std::srand(time(0));
	std::vector<int> vec;
	for (int i = 0; i < 5 ; i++)
		vec.push_back(std::rand() % 10);
	try
	{
		easyfind(vec, 4);
	}
	catch(int nb)
	{
		std::cerr << "Value: " << nb << " not Found" << std::endl;
	}
	return (0);
}
