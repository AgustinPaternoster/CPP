#include "Array.hpp"

int main(void)
{
	try
	{
		Array<int> arr(3);
		Array<int> arr4;
		arr [0] = 1;
		arr[1] = 2;
		arr[2] = 3;
		std::cout << "size: " << arr.size() << std::endl;
		std::cout << "data: " << arr[1] << std::endl;
		Array<int> arr2(arr);
		std::cout << "data: " << arr2[1] << std::endl;
		Array<std::string> arr3(3);
		arr3[0] = "hola";
		arr3[1] = "adios";
		std::cout << arr3[1] << std::endl;
		std::cout << arr3[2] << std::endl;
		arr4 = arr;
		std::cout << arr4[1] << std::endl;
		std::cout << arr4[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	return (0);
}
