#ifndef __ITER_H__
#define __ITER_H__
#include <iostream>
#include <string>

template<typename T>
void print(T data)
{
	std::cout << "value: " << data << std::endl;
}


template<typename T1 , int len, typename F>
void iter(T1 *arr, F function)
{
	for (int i = 0; i < len ; i++ )
		function(arr[i]);
}

#endif