#ifndef __WHATEVER_H__
#define __WHATEVER_H__
#include <iostream>

template<typename T1 , typename T2>
void swap(T1 &value1, T2 &value2)
{
	T1 tmp = value1;
	value1 = value2;
	value2 = tmp;
}

template<typename T1 , typename T2>
T1 min(T1 value1, T2 value2)
{
	if (value1 <  value2)
		return (value1);
	else
		return (value2);
}	

template<typename T1 , typename T2>
T1 max(T1 value1, T2 value2)
{
	if (value1 >  value2)
		return (value1);
	else
		return (value2);
}
#endif