#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberuyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <exception>

int main(void)
{
	Intern someRandomIntern;
	try
	{
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy requests", "Bender");
		if (rrf == NULL)
			throw std::exception();
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	return (0);
}