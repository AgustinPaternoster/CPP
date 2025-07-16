#include "RPN.hpp"
#include <iostream>

int main(int arc , char **argv)
{
	if (arc !=2)
	{
		std::cerr << "Wrong numbers of arguments" << std::endl;
		return (1);
	}
	try
	{
		RPN rnp(argv[1]);
		rnp.parseExpresion();
		rnp.printResult();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}