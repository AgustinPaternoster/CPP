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
	std::vector<int> sp1;
	for (int i = 0; i < 10 ; i++)
		sp1.push_back(std::rand() % 100);
		
	std::vector<int> sp;
	for (int i = 0; i < 10 ; i++)
		sp.push_back(std::rand() % 10);
	printarr(sp);
	sp.insert(sp.end(), sp1.begin(), sp1.end());
	std::cout << "-----------" << std::endl;
	printarr(sp);
	// std::sort(sp.begin(), sp.end());
	// std::cout << "X: " << *sp.begin() << std::endl;
	
	// printarr(sp);
	return (0);
}	
