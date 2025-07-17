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
		void parseExpresion(void);
		void printResult(void)const;
		class RPNException : public std::exception
		{
			const char* what()const throw();
		};
		
		private:
		std::string _expresion;
		std::stack<int> _stk;
		static std::string const _opTokens;
		bool _makeCalculation(char c);
		void _validateExpresion(void);
		// void _characterValidation(char chr);
};


#endif