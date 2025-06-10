#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	try{
		Bureaucrat bc("bureau", 0);
		Form form("test",99,100);
		bc.singForm(form);
		std::cout << form << std::endl;
		form.beSigned(bc);
		
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}