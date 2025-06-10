#include "Form.hpp"
#include <string>
#include <sstream>

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
	_isSigned = true;
	std::cout << bc.getName() << " signed " << _name << " form" << std::endl;
}

void Form::_checkGrade(int grade)
{
	if(grade < 1)
	{	
		Form::GradeTooHighException e;
		e._setGrade(grade);
		e._setGradeNeed(1);
		throw Form::GradeTooHighException();
	}
	if(grade > 150)
	{
		Form::GradeTooLowException e;
		e._setGrade(grade);
		e._setGradeNeed(150);
		throw Form::GradeTooLowException();
	}
}

std::string Form::to_string(int value)
{
	std::ostringstream oss;
	oss << value;
	return oss.str();
}


////// excepcion class ///////////

const char* Form::GradeTooLowException::what() const throw()
{
	// std::string msg = "Error: Input Grade " + Form::to_string(_grade) +
	// 					" must be higher than or equal to required Grade " +
	// 					Form::to_string(_gradeNeeded);
	std::string msg = " prueba 1234";
	return (msg.c_str());
	
	//return ("Grade must be smaller than 151");
}

void Form::GradeTooLowException::_setGrade(int grade)
{
	_grade = grade;
}

void Form::GradeTooLowException::_setGradeNeed(int grade)
{
	_gradeNeeded = grade;
}

int Form::GradeTooLowException::_getGrade(void)
{
	return(_grade);
}

int Form::GradeTooLowException::_getGradeNeed(void)
{
	return(_gradeNeeded);
}

const char* Form::GradeTooHighException::what() const throw()
{
	_eMsg = "hola";
	// msg = "Error: Input Grade " + Form::to_string(_grade) +
	// 					" must be higher than or equal to required Grade " +
	// 					Form::to_string(_gradeNeeded);
	return (_eMsg.c_str());					
}

void Form::GradeTooHighException::_setGrade(int grade)
{
	_grade = grade;
}

void Form::GradeTooHighException::_setGradeNeed(int grade)
{
	_gradeNeeded = grade;
}

int Form::GradeTooHighException::_getGrade(void)
{
	return(_grade);
}

int Form::GradeTooHighException::_getGradeNeed(void)
{
	return(_gradeNeeded);
}

std::ostream& operator<<(std::ostream& os, const Form& other)
{
	os<< "Name: " << other.getName() << ", Grade to sign: " << other.getGradeToSign()
					<< ", Grade to Exec: " << other.getGradeToExec() << ", Is signed: " << other.getIsSigned();
	return(os);
}