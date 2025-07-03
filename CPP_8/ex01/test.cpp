#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

void printarr(std::vector<int> arr)
{
	for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
		std::cout << ": " << *it << std::endl;
}

int main(void)
{
	std::vector<int> sp;
	for (int i = 0; i < 10 ; i++)
		sp.push_back(std::rand() % 5);
	printarr(sp);
	std::sort(sp.begin(), sp.end());
	std::cout << "-----------" << std::endl;
	std::cout << "X: " << *sp.begin() << std::endl;
	
	// printarr(sp);
	return (0);
}	
