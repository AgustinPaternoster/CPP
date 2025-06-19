#include <string>
#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
	(void)argv;
	if (argc < 2 || argc > 2)
	{
		std::cout << "Wrong numbers of arguments" << std::endl;
		return (0);
	}
	try
	{
		std::string input = argv[1];	
		ScalarConverter::convert(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);	
}