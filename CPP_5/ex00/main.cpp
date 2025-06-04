#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat b1("testeo" , 150);
		std::cout << b1 << std::endl;
		Bureaucrat b2("teste02",1);
		b2.incrementGrade();
		std::cout << b2 << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}