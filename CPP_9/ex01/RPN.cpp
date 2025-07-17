#include "RPN.hpp"
#include <ctype.h>
#include <iostream>
#include <stdlib.h>

const std::string RPN::_opTokens = "+-/*";

RPN::RPN(std::string expresion): _expresion(expresion){}

RPN::RPN(const RPN& other):_expresion(other._expresion){}

RPN::~RPN(void){};

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this->_expresion = other._expresion;
	}
	return(*this);
}

void RPN::parseExpresion(void)
{
	_validateExpresion();

	for (std::string::iterator it = _expresion.begin(); it != _expresion.end(); it++)
	{
		if(*it == 32)
		continue;
		if (*(it + 1) != 32 && (it + 1) != _expresion.end())
		throw RPNException();
		if (isdigit(*it))
		{
			_stk.push(*it - 48);
			continue;
		}
		if (!_makeCalculation(*it) )
			throw RPNException();
	}
}

bool RPN::_makeCalculation(char c)
{
	if (_stk.size() < 2)
		return (false);
	int lastNb = _stk.top();
	_stk.pop();
	int firstNb = _stk.top();
	switch (_opTokens.find(c))
	{
	case 0:
		firstNb += lastNb;
		break;
	case 1:
		firstNb -= lastNb;
		break;
	case 2:
		if(_stk.top() == 0)
			return (false);
		firstNb /= lastNb;
		break;
	case 3:
		firstNb *= lastNb;
		break;
	default:
		return(false);
		break;
	}
	_stk.pop();
	_stk.push(firstNb);
	return(true);
}

void RPN::printResult(void)const
{
	if(_stk.size() != 1)
		throw RPNException();
	std::cout << "Result: " << _stk.top() << std::endl;
}

void RPN::_validateExpresion(void)
{
	if (_expresion.size() < 5)
		throw RPNException();

	for (std::string::iterator it = _expresion.begin(); it != _expresion.end(); it++)
	{
		if (*it == 32)
			continue;
		if( !isdigit(*it) && _opTokens.find(*it) == std::string::npos)
			throw RPNException();
	}
	if (*(_expresion.rbegin()) == 32)
			throw RPNException();	
}

/// class exception //
const char* RPN::RPNException::what()const throw()
{
	return("Error");
}


