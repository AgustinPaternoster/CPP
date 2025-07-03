#ifndef __SPAN_H__
#define __SPAN_H__
#include <algorithm>
#include <iostream>
#include <vector>

class Span
{
	public:
		Span(unsigned int nb);
		Span(const Span& other);
		~Span(void);

		Span& operator=(const Span& other);
		void addNumber(int nb);
		int shortestSpan(void);
		int longestSpan(void);
		void addRange(std::vector<int>& source);

		void printVec(void)
		{
			for (std::vector<int>::iterator it = array.begin(); it != array.end(); it++ )
				std::cout << "v: " << *it << std::endl;
		}
		class SizeExceptionType:public std::exception
		{
			const char* what() const throw();
		};
		
		class CalculationException:public std::exception
		{
			const char* what() const throw();
		};

	private:
		unsigned int		N;
		std::vector<int> 	array;


};

#endif