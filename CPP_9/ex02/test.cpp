#include <vector>
#include <iostream>

std::pair<int,int> create(int i, int j)
{
	std::pair<int , int> a;
	a.first = i;
	a.second = j;
	return(a);
	
}
int main(void)
{
	std::vector<std::pair<int,int>> test;
	std::pair<int,int> a;
	a.first = 1;
	a.second = 2;
	

	for (int i = 0; i < 10; i++)
	{
		test.push_back(create(i+3, i+i));
	}
	
	for (std::vector<std::pair<int,int>>::iterator it = test.begin() ; it != test.end(); it++)
	{
		std::cout << (*it).first << " " << (*it).second << std::endl;
	}

	

}