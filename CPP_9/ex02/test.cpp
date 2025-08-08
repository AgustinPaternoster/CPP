#include <vector>
#include <iostream>

void printVect(std::vector<int> vec, char c)
{
	for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << c << "-" << *it << std:: endl;
	}
}

void recursiveOrder(std::vector<int> test)
{
	std::vector<int> firstHalf;
	// std::vector<int> secondHalf;
	if (test.size() < 2)
	{
		printVect(test, '-');
		return;
	}
	for(int i = 0; i < (test.size() / 2) ; i++)
		firstHalf.push_back(test[i]);
	recursiveOrder(firstHalf);	
	// for (int i = test.size() / 2; i < test.size(); i++)
	// 	secondHalf.push_back(test[i]);
	printVect(test, 'f');
	// printVect(secondHalf, 's');

}

int main(int arc, char** argv)
{
	std::vector<int> test = {22,4,77, 1 , 123, 6 , 5, 153, 999};
	recursiveOrder(test);
	return (0);
}