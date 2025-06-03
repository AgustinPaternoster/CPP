#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name)
{
	if (grade > 150)
		throw; // completar exection
	else if ( grade < 1)
		throw; // completar exception
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
	_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	_grade++;
}

void Bureaucrat::GradeTooHighException::setGrade(int grade)
{
	_grade = grade;
}

int Bureaucrat::GradeTooHighException::getGrade(void)const
{
	return(_grade);
} 

const char* Bureaucrat::GradeTooHighException::what()const throw()
{
	std::cout << getGrade() << " is incorrect. Must be bigger than 0" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
}
