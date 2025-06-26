#include <iostream>

template<typename T>
Array<T>::Array(void)
{
	arr = new T[0]();
}

template<typename T>
Array<T>::Array(unsigned int n):len(n)
{
	arr = new T[len]();
}

template<typename T>
Array<T>::Array(const Array& other):len(other.size())
{
	this->arr = new T[len]();
	for (int i = 0 ; i < len ; i++)
		this->arr[i] = other.arr[i];
}


template<typename T>
Array<T>::~Array(void)
{
	delete []arr;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		this->len = other.size();
		delete []this->arr;
		this->arr = new T[this->len]();
		for (int i = 0 ; i < len ; i++)
			this->arr[i] = other.arr[i];
	}
	return (*this);
}


template<typename T>
int Array<T>::size(void)const
{
	return (len);
}

template<typename T>
T& Array<T>::operator[](int index)
{
	if(index < 0 || index >= len)
		throw std::out_of_range("Index out of Range");
	return (arr[index]);
}