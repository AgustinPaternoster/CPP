#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberuyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat bc("test",100);
	AForm *form[3];
	form[0] = new ShrubberuyCreationForm("f1");
	form[1] = new RobotomyRequestForm("f2");
	form[2] = new PresidentialPardonForm("f3");
	for (int i = 0; i < 3; i++)
		bc.singForm(*form[i]);
	for (int i = 0; i < 3; i++)
		bc.executeForm(*form[i]);
	for (int i = 0; i < 3; i++)
		delete form[i];	
	return (0);
}