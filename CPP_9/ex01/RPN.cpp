#include "RPN.hpp"
#include <ctype.h>
#include <iostream>

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
	for (std::string::iterator it = _expresion.begin(); it != _expresion.end(); it++)
	{
		if(*it == 32)
			continue;
		if (*(it + 1) != 32 && (it + 1) != _expresion.end())
			throw RPNException();
		if (isdigit(*it))
			_stk.push(static_cast<float>(*it));
		if (!_makeCalculation(*it))
			throw RPNException();
	}
}

bool RPN::_makeCalculation(char c)
{
	float nb = _stk.top();

	_stk.pop();
	switch (_opTokens.find(c))
	{
	case 0:
		nb += _stk.top();
		break;
	case 1:
		nb -= _stk.top();
		break;
	case 2:
		if(_stk.top() == 0)
			return (false);
		nb /= _stk.top();
		break;
	case 3:
		nb *= _stk.top();
		break;
	default:
		return(false);
		break;
	}
	_stk.pop();
	_stk.push(nb);
	return(true);
}

void RPN::printResult(void)const
{
	if(_stk.size() != 1)
		throw RPNException();
	std::cout << "Result: " << _stk.top() << std::endl;
}

/// class exception //
const char* RPN::RPNException::what()const throw()
{
	return("Error");
}


