#include <iostream>

enum Levels {debug, info, warning, error};

void test(std::string name)
{
	
	switch (level)
	{
	case 0:
		{
			std::cout << level << std::endl;
			level = info;
		}
	case 1:
		{
			std::cout << level << std::endl;
			level = warning;
		}
	case 2:
		{
			std::cout << level << std::endl;
			level = error;
		}
	case 3:
		{
			std::cout << level << std::endl;
			break;
		}
	default:
		break;
	}
}

int main(void)
{
	
	return (0);
}