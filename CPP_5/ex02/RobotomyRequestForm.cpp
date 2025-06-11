#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
:AForm("robotomy", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
:AForm(other.getName(), other.getGradeToSign(), other.getGradeToSign()), _target(other.getTarget()){}

RobotomyRequestForm::~RobotomyRequestForm(void){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		this->setIsigned(other.getIsSigned());
	}
	return(*this);
}

std::string RobotomyRequestForm::getTarget(void)const
{
	return(_target);
}

void RobotomyRequestForm::executeAction(void)const
{
	std::cout << "BZZZZZZZRRRRRRRRRRRRRRR!" << std::endl;
	std::cout << this->getTarget() << " has been  has been robotomized successfully 50% of the time." 
				<< std::endl;
}
