#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(void)
{
	MutantStack<int> stk;
	
	stk.push(10);
	stk.push(11);
	stk.push(12);
	
	MutantStack<int>::iterator init;
	MutantStack<int>::iterator end;
	
	init = stk.begin();
	end = stk.end();
	
	std::cout << "------ stack -------" << std::endl;
	
	while(init != end)
	{
		std::cout << "v: " << *init << std::endl;
		++init;
	}
	
	
	MutantStack<int> stk2(stk);
	std::cout << "s: " << stk2.size() << std::endl;
	
	std::cout << "------ list -------" << std::endl;
	
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(11);
	lst.push_back(12);

	std::list<int>::iterator ini = lst.begin();
	std::list<int>::iterator en  = lst.end();

	while(ini != en)
	{
		std::cout << "v: " << *ini << std::endl;
		++ini;
	}
	return (0);
}