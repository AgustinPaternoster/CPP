#include "Harl.hpp"
#include <iostream>

int main (int arc, char **argv)
{
	(void)arc;
	if (arc != 2)
	{
		std::cout <<  "wrong numbers of arguments" << std::endl;
		return (1);
	}
	Harl harl;
	
	harl.complain(argv[1]);
	return (0);
}