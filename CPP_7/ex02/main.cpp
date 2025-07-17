// #include "Array.hpp"

// int main(void)
// {
// 	try
// 	{
// 		Array<int> arr(3);
// 		Array<int> arr4;
// 		arr [0] = 1;
// 		arr[1] = 2;
// 		arr[2] = 3;
// 		std::cout << "size: " << arr.size() << std::endl;
// 		std::cout << "data: " << arr[1] << std::endl;
// 		Array<int> arr2(arr);
// 		std::cout << "data: " << arr2[1] << std::endl;
// 		Array<std::string> arr3(3);
// 		arr3[0] = "hola";
// 		arr3[1] = "adios";
// 		std::cout << arr3[0] << std::endl;
// 		std::cout << arr3[1] << std::endl;
// 		arr4 = arr;
// 		std::cout << arr4[1] << std::endl;
// 		std::cout << arr4[5] << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	return (0);
// }

#include <iostream>
#include "Array.hpp"
#include <cstdlib>  // Necesaria para srand() y rand()
#include <ctime>  

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
		Array<int> tmp = numbers;
        Array<int> test(tmp);
		std::cout << "- " << numbers[25] << std::endl;
		std::cout << "- " << tmp[25] << std::endl;
		std::cout << "- " << test[25] << std::endl;

    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

    delete [] mirror;//
    return 0;
}
	
