#include "RPN.hpp"

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

const char* RPN::RPNException::what()const throw()
{
	return("Error");
}


