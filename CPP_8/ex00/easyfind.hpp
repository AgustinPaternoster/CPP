#ifndef __EASYFIND_H__
#define __EASYFIND_H__
#include <iostream>
#include <algorithm>


template<typename T>
void easyfind(T &co , int nb)
{
	typename T::iterator it = std::find(co.begin() , co.end(), nb);
	if (*it == nb)
		std::cout << "Value: " << *it << " found" << std::endl;
	else
		throw nb;
}

#endif
