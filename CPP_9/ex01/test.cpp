#include <stack>
#include <iostream>
#include <string>
#include <ctype.h>

int main(void)
{
	char c = 'a';
	std:: string oper = "+-/*";
	switch (oper.find(c))
	{
	case 0:
		std::cout << "+" << std::endl;
		break;
	case 1:
		std::cout << "-" << std::endl;
		break;
	case 2:
		std::cout << "/" << std::endl;
		break;
	case 3:
		std::cout << "*" << std::endl;
		break;
	default:
		std::cout << "NO" << std::endl;
		break;
	}
	return (0);
}