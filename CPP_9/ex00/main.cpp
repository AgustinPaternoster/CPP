#include "BitcoinExchange.hpp"
#include <iostream>
#define DATA "./data.csv"

int main(int argc , char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Wrong number of argument" << std::endl;
		return(1);
	}
	try
	{
		BitcoinExchange test;
		test.loadDB(DATA);
		test.loadInputDB(argv[1]);
		// test.printData();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}