#include <iostream>

int main(void)
{
	

	int * a[3];


	for (int i = 0; i < 3; i++)
	{
		if (a[i] == NULL)
			std::cout << "NULL" << std::endl;
		if(a[i] != NULL )
			std::cout << "NO NULL" << std::endl;
	}
	return (0);	

}
