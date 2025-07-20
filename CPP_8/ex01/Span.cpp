#include "Span.hpp"

Span::Span(unsigned int nb):N(nb){};
Span::Span(const Span& other):N(other.N)
{
		array = other.array;
}

Span::~Span(void){};

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		N = other.N;
		array = other.array;
	}
	return (*this);
}
void Span::addNumber(int nb)
{
	if (array.size() >= static_cast<long>(N))
		throw Span::SizeExceptionType();
	array.push_back(nb);
}

int Span::shortestSpan(void)
{
	if (array.size() < 2)
		throw Span::CalculationException();
	std::sort(array.begin(), array.end());
	for (std::vector<int>::iterator it = array.begin() ; it != array.end(); it++)
	{
		if (*it != *array.begin())
			return (*it - *array.begin());
	}
	return(0);
}

int Span::longestSpan(void)
{
	if (array.size() < 2)
		throw Span::CalculationException() ;
	int min = *std::min_element(array.begin(), array.end());
	int max = *std::max_element(array.begin(), array.end());
	return (max - min);
}

// void Span::addRange(std::vector<int> &source)
// {
// 	if(array.size() + source.size() > N)
// 		throw Span::SizeExceptionType();
// 	array.insert(array.end(), source.begin(), source.end());
// }


/// exceptions ////
const char* Span::SizeExceptionType::what() const throw()
{
	return ("No more free space");
}

const char* Span::CalculationException::what() const throw()
{
	return ("Not enough elements");
}