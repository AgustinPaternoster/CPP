#include <stack>

template<typename T>
MutantStack<T>::iterator::iterator(void){}

template<typename T>
MutantStack<T>::iterator::iterator(T *ptr)
{
	_ptr = ptr;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	T *ptr = &this->c.front();
	return(MutantStack<int>::iterator(ptr));
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	T *ptr = &this->c.back();
	return(MutantStack<int>::iterator(++ptr));
}


template<typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator=(
const typename MutantStack<T>::iterator& other)
{
	if(this != &other)
	{
		_ptr = other._ptr;
	}
	return (*this);
}

template<typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator++(void)
{
	_ptr++;
	return (*this);
}

template<typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator--(void)
{
	_ptr--;
	return (*this);
}

template<typename T>
bool MutantStack<T>::iterator::operator!=(const typename MutantStack<T>::iterator& other)
{
	if (this->_ptr == other._ptr)
		return (false);
	return (true);
}

template<typename T>
T MutantStack<T>::iterator::operator*(void)
{
	return (*this->_ptr);
}
