#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberuyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
	PresidentialPardonForm form("home");
	Bureaucrat bc("test",5);
	bc.singForm(form);
	std::cout << form << std::endl;
	bc.executeForm(form);
	
	return (0);
}