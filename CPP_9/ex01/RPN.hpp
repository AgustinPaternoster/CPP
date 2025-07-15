#ifndef __RNP_H__
#define __RNP_H__
#include <stack>
#include <string>

class RPN
{
	public:
		RPN(std::string expresion);
		RPN(const RPN& other);
		~RPN(void);

		RPN& operator=(const RPN& other);

		class RPNException : public std::exception
		{
				const char* what()const throw();
		};
			
	private:
		std::string _expresion;
		std::stack<float> _stk;
		static std::string const _opTokens;
		// void _characterValidation(char chr);
};


#endif