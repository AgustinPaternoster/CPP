#ifndef __AFORM_H__
#define __AFORM_H__
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm(std::string name, int gradeToSign, int gradeToExec);
		AForm(const AForm& other);
		virtual ~AForm(void);

		AForm& operator=(const AForm& other);
		std::string getName(void)const;
		bool getIsSigned(void)const;
		int getGradeToSign(void)const;
		int getGradeToExec(void)const;
		void setIsigned(bool sign);
		void beSigned(Bureaucrat& bc);
		void execute(Bureaucrat const& executor)const;
		virtual void executeAction(void) const = 0; 		

		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		class AlreadySignedException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		class NotSignedException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		
	private:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExec;
		bool				_isSigned;
		void _checkGrade(int grade);
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif