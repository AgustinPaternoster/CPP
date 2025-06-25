#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>

Base* generate(void)
{

	srand(time(0));
	int nb = rand() % 3;
	switch (nb)
	{
		case 0:
		{
			return(new A);
			break;
		}
		case 1:
		{
			return(new B);
			break;
		}
			case 2:
		{
			return(new C);
			break;
		}
		default:
		{	
			return (NULL);
			break;
		}
	}
}

void indentify(Base* p)
{
	std::cout << "indentify pointers:" << std::endl;
	if (dynamic_cast<A*>(p))
		std::cout << "type: A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "type: B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "type: C" << std::endl;
}

void indentify(Base& p)
{
	std::cout << "indentify references:" << std::endl;
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "type: A" << std::endl;
	}
	catch(const std::exception& e){}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "type: B" << std::endl;
	}
	catch(const std::exception& e){}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "type: C" << std::endl;
	}
	catch(const std::exception& e){}
}

int main(int arc , char **argv)
{
	(void)argv;
	if (arc > 1)
	{
		std::cout << "Wrong numbers of parameters" << std::endl;
		return (0);
	}
	Base *test = generate();
	indentify(test);
	indentify(*test);
	delete test	;
	return (0);
}