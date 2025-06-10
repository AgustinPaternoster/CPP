#include "Form.hpp"
#include <string>


Form::Form(std::string name, int gradeToSign, int gradeToExec):
		_name(name),
		_gradeToSign(gradeToSign),
		_gradeToExec(gradeToExec),
		_isSigned(false)
{
	_checkGrade(gradeToSign);
	_checkGrade(gradeToExec);
}

Form::Form(const Form& other):_name(other._name),
							_gradeToSign(other._gradeToSign),
							_gradeToExec(other._gradeToExec),
							_isSigned(other._isSigned){}

Form::~Form(void){}

Form& Form::operator=(const Form& other)
{
	if(this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

bool Form::getIsSigned(void)const
{
	return(_isSigned);
}

int Form::getGradeToSign(void)const
{
	return(_gradeToSign);
}

int Form::getGradeToExec(void)const
{
	return(_gradeToExec);
}
std::string Form::getName(void)const
{
	return(_name);
}

void Form::beSigned(Bureaucrat& bc)
{
	if (bc.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	if (_isSigned == true)
		throw Form::AlreadySignedException();
	_isSigned = true;
	std::cout << bc.getName() << " signed " << _name << " form" << std::endl;
}

void Form::_checkGrade(int grade)
{
	if(grade < 1)
	{	
		throw Form::GradeTooHighException();
	}
	if(grade > 150)
	{
		throw Form::GradeTooLowException();
	}
}


////// excepcion class ///////////

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low for form.");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high for form.");					
}

const char* Form::AlreadySignedException::what() const throw()
{
	return ("Form already signied.");					
}

std::ostream& operator<<(std::ostream& os, const Form& other)
{
	os<< "Name: " << other.getName() << ", Grade to sign: " << other.getGradeToSign()
					<< ", Grade to Exec: " << other.getGradeToExec() << ", Is signed: " << other.getIsSigned();
	return(os);
}