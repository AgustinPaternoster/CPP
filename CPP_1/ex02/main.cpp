#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string& stringREF = str;


	std::cout << "memory addres of the string valiable: " << &str << std::endl;
	std::cout << "memory addres held by stringPTR: " << stringPTR << std::endl;
	std::cout << "memory addres of the stringREF: " << &stringREF << std::endl;

	std::cout << "the value of the string valiable: " << str << std::endl;
	std::cout << "the value pointed by stringPTR: " << *stringPTR  << std::endl;
	std::cout << "the value pointed by stringREF: " << stringREF << std::endl;
		

	return (0);
}