#ifndef __ARRAY_H__
#define __ARRAY_H__

template<typename T>
class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& other);
		~Array(void);

		Array& operator=(const Array& other);
		T& operator[](int index);
		int size(void)const;
		
		private:
			int _len;
			T *arr;
};

#include "Array.tpp"

#endif