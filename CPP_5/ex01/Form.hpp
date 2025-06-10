#ifndef __FORM_H__
#define __FORM_H__
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	public:
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form& other);
		~Form(void);
		static std::string to_string(int value);

		Form& operator=(const Form& other);
		std::string getName(void)const;
		bool getIsSigned(void)const;
		int getGradeToSign(void)const;
		int getGradeToExec(void)const;
		void beSigned(Bureaucrat& bc);

		class GradeTooLowException: public std::exception
		{
			private: 
				int _grade;
				int _gradeNeeded;

			public:
				const char* what() const throw();
				void	_setGrade(int grade);
				int		_getGrade(void);
				void	_setGradeNeed(int grade);
				int		_getGradeNeed(void);

		};

		class GradeTooHighException: public std::exception
		{
			private: 
				int _grade;
				int _gradeNeeded;
				std::string _eMsg;

			public:
				const char* what() const throw();
				void	_setGrade(int grade);
				int		_getGrade(void);
				void	_setGradeNeed(int grade);
				int		_getGradeNeed(void);

		};

	private:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExec;
		bool				_isSigned;
		void _checkGrade(int grade);
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif