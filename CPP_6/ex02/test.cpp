#include <iostream>
#include <stdlib.h>
#include <ctime>


int main(void)
{
	srand(time(0));
	int i = std::rand() % 3;
	std::cout << i << std::endl;
	return (0);


}