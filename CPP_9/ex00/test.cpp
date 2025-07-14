#include <map>
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>

// time_t parseDate()


int main(void)
{
	std::time_t timer;
	std::cout << "x: " << std::time(&timer) << std::endl;

	return (0);

	
}