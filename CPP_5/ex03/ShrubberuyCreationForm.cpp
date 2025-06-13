#include "ShrubberuyCreationForm.hpp"
#include <iostream>
#include <fstream>


ShrubberuyCreationForm::ShrubberuyCreationForm(std::string target)
:AForm("shrubberuy", 145 , 137) , _target(target) {}

ShrubberuyCreationForm::ShrubberuyCreationForm(const ShrubberuyCreationForm& other)
:AForm(other.getName(), 
other.getGradeToSign(), 
other.getGradeToExec()), _target(other.getTarget()){}

ShrubberuyCreationForm::~ShrubberuyCreationForm(void){};

ShrubberuyCreationForm& ShrubberuyCreationForm::operator=(const ShrubberuyCreationForm& other)
{
	if(this != &other)
	{
		this->setIsigned(other.getIsSigned());
	}	
	return (*this);
}

std::string ShrubberuyCreationForm::getTarget(void)const
{
	return (_target);
}

void ShrubberuyCreationForm::executeAction(void)const
{
	std::ofstream file;
	std::string name = _target + "_shrubbery";
	file.open(name.c_str());
	if (!file.is_open())
	{	
		std::cout << "Error file" << std::endl;
		return;
	}
	file << "TREES" << std::endl << "TREES" << std::endl << "TREES" << std::endl << "TREES";
	file.close();
}