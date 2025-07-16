#include <iostream>

template<typename T>
Array<T>::Array(void)
{
	arr = new T[0]();
}

template<typename T>
Array<T>::Array(unsigned int n):_len(n)
{
	arr = new T[_len]();
}

template<typename T>
Array<T>::Array(const Array& other):_len(other.size())
{
	this->arr = new T[_len]();
	for (int i = 0 ; i < _len ; i++)
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
		this->_len = other.size();
		delete []this->arr;
		this->arr = new T[this->_len]();
		for (int i = 0 ; i < _len ; i++)
			this->arr[i] = other.arr[i];
	}
	return (*this);
}


template<typename T>
int Array<T>::size(void)const
{
	return (_len);
}

template<typename T>
T& Array<T>::operator[](int index)
{
	if(index < 0 || index >= _len)
		throw std::out_of_range("Index out of Range");
	return (arr[index]);
}