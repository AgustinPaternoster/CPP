#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target)
:AForm("Presidential", 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
:AForm(other.getName(), other.getGradeToSign(), other.getGradeToSign()), _target(other.getTarget()){}

PresidentialPardonForm::~PresidentialPardonForm(void){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		this->setIsigned(other.getIsSigned());
	}
	return(*this);
}

std::string PresidentialPardonForm::getTarget(void)const
{
	return(_target);
}

void PresidentialPardonForm::executeAction(void)const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." 
				<< std::endl;
}
