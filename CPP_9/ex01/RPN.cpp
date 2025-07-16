#include "RPN.hpp"
#include <ctype.h>

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

void RPN::_parseExpresion(void)
{
	for (std::string::iterator it = _expresion.begin(); it != _expresion.end(); it++)
	{
		if(*it == 32)
			continue;
		if (*(it + 1) != 32 && (it + 1) != _expresion.end())
			throw RPNException();
		
	}
}

bool RPN::_makeCalculation(char c)
{
	int token;
	if (isdigit(c))
		_stk.push(static_cast<float>(c));
	if(_opTokens.find(c) == std::string::npos)
		return(false);
	switch (expression)
	{
	case constant expression:
		/* code */
		break;
	
	default:
		break;
	}

}

/// class exception //
const char* RPN::RPNException::what()const throw()
{
	return("Error");
}


