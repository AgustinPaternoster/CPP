#ifndef __MUTANTSTACK_H__
#define __MUTANTSTACK_H__
#include <iostream>
#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack<T>& other);
		~MutantStack(void);
		
		MutantStack<T>& operator=(const MutantStack<T>& other);

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin(void);
		iterator end(void);
};

#include "MutantStack.tpp"
#endif