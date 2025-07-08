#ifndef __MUTANTSTACK_H__
#define __MUTANTSTACK_H__
#include <iostream>
#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{

	public:
		class iterator
		{
			
			public:
				iterator(void);
				iterator(T *ptr);
				iterator(const iterator& other);

				iterator& operator=(const iterator& other);
				bool operator!=(const iterator& other);
				iterator& operator++(void);
				iterator& operator--(void);
				T operator*(void);
			private:
				T * _ptr;
		};

		
		iterator begin(void);
		iterator end(void);
	
};

#include "MutantStack.tpp"
#endif