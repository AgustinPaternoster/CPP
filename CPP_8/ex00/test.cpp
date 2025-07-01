#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <stdlib.h>

class Test
{
	public:
	int a;
	Test(int nb):a(nb){};
	void getter(void){ 
		std::cout << "valor: " << a << std::endl;}
};

void multi(Test &x)
{
	x.a += 10;
}

int main(void)
{
	int nb = 2;
	std::vector<int> vec;
	for (int i = 0 ; i < 20 ; i++)
		vec.push_back(std::rand() % 10);	
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << "int: " << *it << std::endl;
	std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), nb);
	if (*it == nb)
		std::cout << "valor: " << *it << " encontrado" << std::endl;
	else	
		std::cout << "valor no encontrado" << std::endl;
	return (0);
}