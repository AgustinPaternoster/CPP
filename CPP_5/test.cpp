#include <iostream>
#include <exception>

int main(void)
{
	int a = 10;
	int b = 0;
	try
	{
		std::cout << a/b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}