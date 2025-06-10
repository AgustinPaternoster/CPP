#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name)
{
	if (grade > 150)
	{
		throw  Bureaucrat::GradeTooLowException();
	}
	else if ( grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):
		_name(other._name), _grade(other._grade){}

Bureaucrat::~Bureaucrat(void){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}
std::string Bureaucrat::getName(void)const
{
	return(_name);
}

int Bureaucrat::getGrade(void)const
{
	return(_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (--_grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
}

void Bureaucrat::decrementGrade(void)
{
	if(++_grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

const char* Bureaucrat::GradeTooHighException::what()const throw()
{
	return("Grade must be bigger than 0");
}

const char* Bureaucrat::GradeTooLowException::what()const throw()
{
	return("Grade must be smaller than 151");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (os);	
}

