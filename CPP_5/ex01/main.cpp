#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	try{
		// Bureaucrat bc("bureau", 100);
		Form form("test",151,100);
		// form.beSigned(bc);
		// std::cout << form << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}