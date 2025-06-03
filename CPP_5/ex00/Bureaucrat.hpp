#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__
#include <string>
#include <exception>

class Bureaucrat
{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat(void);

		Bureaucrat&	operator=(const Bureaucrat& other);
		std::string	getName(void)const;
		int 		getGrade(void)const;
		void		incrementGrade(void);
		void		decrementGrade(void);

		class GradeTooHighException: public std::exception
		{
			private:
				int _grade;
			public:
				const char* what() const throw();
				void	setGrade(int grade);
				int		getGrade(void)const;
		};
	private:
		const	std::string _name;
		int 	_grade; 
};

#endif
