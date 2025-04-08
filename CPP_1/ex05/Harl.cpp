#include <iostream>
#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl is active" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Harl is off" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
}

void Harl::printmsg(void)
{
	std::cout << "allowed levels:" << std::endl << "debug"
			  << std::endl << "info" <<	std::endl << "warning"
			  << std::endl << "error" << std::endl;
}

void Harl::complain(std::string level)
{
	typedef void (Harl::*fnpointer)(void);
	std::string levels[4] = {"debug", "info", "warning", "error"};
	fnpointer fnp[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0 ; i < 4 ; i++)
	{
		if (!levels[i].compare(level))
		{
			(this->*fnp[i])();
			return;
		}
	}
	printmsg();	
}