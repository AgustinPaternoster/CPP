#include "PmergeMe.hpp"
#include <stdlib.h>
#include <climits>
#include <iostream>
#include <cerrno>
#include <cmath>

FordJohnsonAlg::FordJohnsonAlg(void){};

FordJohnsonAlg::FordJohnsonAlg(const FordJohnsonAlg& other)
{
	*this = other;
}

FordJohnsonAlg& FordJohnsonAlg::operator=(const FordJohnsonAlg& other)
{
	(void)other;
	return(*this);
}

void FordJohnsonAlg::FordJohnsonAlg::PmergeVec::_addSequece(char** argv)
{
	long int nb;
	char *endptr;
	int i = 1;
	_before = clock();

	while(argv[i])
	{
		nb = strtol(argv[i], &endptr, 10);
		if(endptr == argv[i])
			throw FordJohnsonAlg::NumberException("Error: No digits were found");
		else if (*endptr != '\0')
			throw FordJohnsonAlg::NumberException("Error: Invalid character");
		else if (errno == ERANGE || (nb > INT_MAX && nb < INT_MIN) || nb < 0)
			throw FordJohnsonAlg::NumberException("Error: Wrong number");
		_sequence.push_back(static_cast<int>(nb));
		i++;
	}
}

void FordJohnsonAlg::PmergeVec::_createPairs(void)
{
	std::vector<int>::iterator it = _sequence.begin();
	while(it != _sequence.end())
	{
		if ((it + 1) == _sequence.end())
		{
			_struggler = *it;			
			break;
		}
		else
		{
			_vecPair.push_back(std::make_pair(*it,*(it + 1)));
			if(*it < *(it + 1))
				std::swap(_vecPair.back().first, _vecPair.back().second);
			}	
		it += 2;
	}
}

std::vector<std::pair<int,int> > FordJohnsonAlg::PmergeVec::_recursiveOrder(std::vector<std::pair<int,int> > vecPair)
{
	std::vector<std::pair<int,int> > firstHalf;
	std::vector<std::pair<int,int> > secondHalf;

	if(vecPair.size() < 2)
		return (vecPair);
	
	int half = vecPair.size() / 2;
	for (int i = 0; i < half; i++)
		firstHalf.push_back(vecPair[i]);
	for (int i = half; i < (int)vecPair.size(); i++)
		secondHalf.push_back(vecPair[i]);
	return(_merge(_recursiveOrder(firstHalf),_recursiveOrder(secondHalf)));
}

std::vector<std::pair<int,int> > FordJohnsonAlg::PmergeVec::_merge(std::vector<std::pair<int,int> > first, std::vector<std::pair<int,int> > second)
{
	std::vector<std::pair<int,int> > result;
	while(first.size() > 0 && second.size() > 0)
	{
		if(first[0].first > second[0].first)
		{
			result.push_back(second[0]);
			second.erase(second.begin());
		}
		else
		{
			result.push_back(first[0]);
			first.erase(first.begin()); 
		}
	}
	while (first.size() > 0)
	{
		result.push_back(first[0]);
		first.erase(first.begin()); 
	}
	
	while (second.size() > 0)
	{
		result.push_back(second[0]);
		second.erase(second.begin());
	}
	return (result);	
}

void FordJohnsonAlg::PmergeVec::orderNumbers(char** av)
{
	_addSequece(av);
	_createPairs();
	_vecPair = _recursiveOrder(_vecPair);
	_splitPairs();
	_createInsertionOrder();
	_insertNumber();
}
void FordJohnsonAlg::PmergeVec::_splitPairs(void)
{
	for(std::vector<std::pair<int,int> >::iterator it = _vecPair.begin(); it != _vecPair.end(); it++)
	{
		_mainSequence.push_back((*it).first);
		_pendSequence.push_back((*it).second);
	}		
}

void FordJohnsonAlg::PmergeVec::_createJacobSeq(int size, std::vector<int>& seq)
{
	int value;
	int i = 2;
	while (true)
	{
		value = (pow(2,i) - pow(-1,i))/3;
		if (value > size)
			break;
		seq.push_back(value - 1);
		i++;
	}
}

void FordJohnsonAlg::PmergeVec::_createInsertionOrder(void)
{
	std::vector<int> jacobSeq; 
	int size = _pendSequence.size();
	_createJacobSeq(size,jacobSeq);
	for(std::vector<int>::iterator it = jacobSeq.begin(); it != jacobSeq.end(); it++)
	{
		if(it == jacobSeq.begin())
		{
			_insertionIndex.push_back(*it);
			continue;
		}
		if(*it - *(it - 1) == 2)
		{
			_insertionIndex.push_back(*it);
			_insertionIndex.push_back(*it - 1);
		}
		else
		{
			_insertionIndex.push_back(*it);
			for(int i = *it - 1; i > *(it - 1); i--)
				_insertionIndex.push_back(i);
		}	
		if ((it + 1) == jacobSeq.end())
		{
			for(int i = size - 1; i > *it; i--)
				_insertionIndex.push_back(i);
		}
	}
}

void FordJohnsonAlg::PmergeVec::_BinarySearchInsert(int value)
{
	int indMin = 0;
	int indMax =  _mainSequence.size() - 1;
	int middle;
	
	if(value >= _mainSequence.back())
	{
		_mainSequence.push_back(value);
		return;
	}
	while(indMin <= indMax)
	{
		middle = (indMin + indMax) / 2;
		if(value == _mainSequence[middle])
		{	
			_mainSequence.insert(_mainSequence.begin() + middle, value);
			return;
		}
		if(value > _mainSequence[middle])
		indMin = middle + 1;
		else
		indMax = middle - 1;
	}
	if (value <= _mainSequence[indMin])
	_mainSequence.insert(_mainSequence.begin() + indMin, value);
}

void FordJohnsonAlg::PmergeVec::_insertNumber(void)
{
	for(std::vector<int>::iterator it = _insertionIndex.begin(); it != _insertionIndex.end(); it++)
	{
		_BinarySearchInsert(_pendSequence[*it]);
	}
	if (_sequence.size() % 2 != 0)
		_BinarySearchInsert(_struggler);
	_processTime = clock() - _before;
}

void FordJohnsonAlg::PmergeVec::printSequence(void)
{
	std::cout << "Before: ";
	for (std::vector<int>::iterator it = _sequence.begin(); it != _sequence.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	std::cout << "After:  ";
	for (std::vector<int>::iterator it = _mainSequence.begin(); it !=  _mainSequence.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void FordJohnsonAlg::PmergeVec::printTime(void)
{
	std::cout << "Time to process a range of " << _sequence.size() << " elements with std::vector: " 
			  << (float)_processTime / CLOCKS_PER_SEC << " seconds" << std::endl;
}

///excetion function ///
FordJohnsonAlg::NumberException::NumberException(std::string msg):_errMsg(msg){}

FordJohnsonAlg::NumberException::~NumberException(void)throw(){};

const char* FordJohnsonAlg::NumberException::what()const throw()
{
	return(_errMsg.c_str());
}