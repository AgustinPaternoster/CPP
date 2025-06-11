#include "AForm.hpp"
#include <string>


AForm::AForm(std::string name, int gradeToSign, int gradeToExec):
		_name(name),
		_gradeToSign(gradeToSign),
		_gradeToExec(gradeToExec),
		_isSigned(false)
{
	_checkGrade(gradeToSign);
	_checkGrade(gradeToExec);
}

AForm::AForm(const AForm& other):_name(other._name),
							_gradeToSign(other._gradeToSign),
							_gradeToExec(other._gradeToExec),
							_isSigned(other._isSigned){}

AForm::~AForm(void){}

AForm& AForm::operator=(const AForm& other)
{
	if(this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

bool AForm::getIsSigned(void)const
{
	return(_isSigned);
}

int AForm::getGradeToSign(void)const
{
	return(_gradeToSign);
}

int AForm::getGradeToExec(void)const
{
	return(_gradeToExec);
}
std::string AForm::getName(void)const
{
	return(_name);
}

void AForm::setIsigned(bool sign)
{
	_isSigned = sign;
}

void AForm::beSigned(Bureaucrat& bc)
{
	if (bc.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	if (_isSigned == true)
		throw AForm::AlreadySignedException();
	_isSigned = true;
}

void AForm::execute(Bureaucrat const& executor)const
{
	if(_isSigned == false)
		throw AForm::NotSignedException();
	if(executor.getGrade() > _gradeToExec)
		throw AForm::GradeTooLowException();
	executeAction();
}

void AForm::_checkGrade(int grade)
{
	if(grade < 1)
	{	
		throw AForm::GradeTooHighException();
	}
	if(grade > 150)
	{
		throw AForm::GradeTooLowException();
	}
}


////// excepcion class ///////////

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low for form.");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high for form.");					
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return ("Form already signied.");					
}

const char* AForm::NotSignedException::what() const throw()
{
	return("Form not signed");
}

std::ostream& operator<<(std::ostream& os, const AForm& other)
{
	os<< "Name: " << other.getName() << ", Grade to sign: " << other.getGradeToSign()
					<< ", Grade to Exec: " << other.getGradeToExec() << ", Is signed: " << other.getIsSigned();
	return(os);
}