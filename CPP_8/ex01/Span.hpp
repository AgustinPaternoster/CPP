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
	
		template<typename T>
		void addRange(T init, T end)
		{
			if(std::distance(init,end) + array.size() > static_cast<long>(N))
				throw Span::SizeExceptionType();
			array.insert(array.end(), init , end);
			
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