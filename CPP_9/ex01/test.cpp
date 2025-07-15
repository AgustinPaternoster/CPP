#include <stack>
#include <iostream>
#include <string>
#include <ctype.h>

int main(void)
{
	std:: string oper = "+-/*";
	std::string txt =  "8 9 * 9 - 9 - 9 - 4 - 1 +";
	for (std::string::iterator it = txt.begin(); it != txt.end(); it++)
	{
		if (*it == 32)
			continue;
		if (*(it + 1) != 32 && (it + 1) != txt.end())
		{
			std::cout << "error" << std::endl;
			return (1);
		}
		if (isdigit(*it))
			std::cout <<  *it;
	}
	std::cout << std::endl;

	return (0);
}