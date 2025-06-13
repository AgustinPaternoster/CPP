#include "Intern.hpp"
#include <iostream>
#include "ShrubberuyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
	_namesForm[0] = "shrubberuy creation";
	_namesForm[1] = "robotomy request";
	_namesForm[2] = "presidential pardon";
}

Intern::~Intern(void){}

AForm* Intern::makeForm(std::string name, std::string target)
{
	int i = 0;
	AForm* form = NULL;

	while(i < 3 && _namesForm[i].compare(name))
		i++;
	switch (i)
	{
	case 0:
		form = new ShrubberuyCreationForm(target);
		break;
	case 1:
		form = new RobotomyRequestForm(target);
		break;
	case 2:
		form = new PresidentialPardonForm(target);
		break;
	default:
		std::cout << "there is no form with the name: " << name << std::endl;
		break;
	}
	if (form != NULL)
		std::cout << "Intern creates " << name << " form" << std::endl; 
	return(form);
}

