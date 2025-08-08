#include "PmergeMe.hpp"
#include <stdlib.h>
#include <climits>
#include <iostream>
#include <cerrno>

void PmergeMe::addSequece(char** argv)
{
	long int nb;
	char *endptr;
	int i = 1;

	while(argv[i])
	{
		nb = strtol(argv[i], &endptr, 10);
		if(endptr == argv[i])
			throw PmergeMe::NumberException("Error: No digits were found");
		else if (*endptr != '\0')
			throw PmergeMe::NumberException("Error: Invalid character");
		else if (errno == ERANGE || (nb > INT_MAX && nb < INT_MIN) || nb < 0)
			throw PmergeMe::NumberException("Error: Wrong number");
		_sequence.push_back(static_cast<int>(nb));
		i++;
	}
}

void PmergeMe::createPairs(void)
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

std::vector<std::pair<int,int> > PmergeMe::_recursiveOrder(std::vector<std::pair<int,int> > vecPair)
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

std::vector<std::pair<int,int> > PmergeMe::_merge(std::vector<std::pair<int,int> > first, std::vector<std::pair<int,int> > second)
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

void PmergeMe::orderNumbers(char** av)
{
	addSequece(av);
	createPairs();
	_vecPair = _recursiveOrder(_vecPair);
	splitPairs();

}
void PmergeMe::splitPairs(void)
{
	for(std::vector<std::pair<int,int> >::iterator it = _vecPair.begin(); it != _vecPair.end(); it++)
	{
		_mainSequence.push_back((*it).first);
		_pendSequence.push_back((*it).second);
	}
	if (_pendSequence[0] <= _mainSequence[0])
	{
			_mainSequence.insert(_mainSequence.begin(),_pendSequence[0]);
			_pendSequence.erase(_pendSequence.begin());
	}		
}
void PmergeMe::print (void)
{
	for(std::vector<int>::iterator it = _mainSequence.begin(); it != _mainSequence.end(); it++)
		std::cout << *it << " - ";

	std::cout << std::endl;

	for(std::vector<int>::iterator it = _pendSequence.begin(); it != _pendSequence.end(); it++)
		std::cout << *it << " - ";

	std::cout << std::endl;

	if (_sequence.size() % 2 != 0)
		std::cout << _struggler << std::endl;
}
PmergeMe::NumberException::NumberException(std::string msg):_errMsg(msg){}

PmergeMe::NumberException::~NumberException(void)throw(){};

const char* PmergeMe::NumberException::what()const throw()
{
	return(_errMsg.c_str());
}