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
	int minDistance;
	int distance;

	if (array.size() < 2)
		throw Span::CalculationException();
	std::sort(array.begin(), array.end());
	std::vector<int>::iterator it = array.begin();
	minDistance = *(it + 1) - *it;
	while (it != array.end() - 1)
	{
		distance = *(it + 1) - *it;
		if (distance == 0)
			return (distance);
		if (distance < minDistance)
			minDistance = distance;
		it++;
	}
	return (minDistance);
}

int Span::longestSpan(void)
{
	if (array.size() < 2)
		throw Span::CalculationException() ;
	int min = *std::min_element(array.begin(), array.end());
	int max = *std::max_element(array.begin(), array.end());
	return (max - min);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (begin >= end)
		throw Span::InteatorException();
	if(std::distance(begin,end) + array.size() > static_cast<long>(N))
		throw Span::SizeExceptionType();
	array.insert(array.end(), begin , end);
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

const char* Span::InteatorException::what() const throw()
{
	return ("Wrong iterators");
}