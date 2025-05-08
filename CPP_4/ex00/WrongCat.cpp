#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void):WrongAnimal("WrongCat")
{
	std::cout << "WrongCat has been created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& rsc): WrongAnimal(rsc)
{
		std::cout << "WrongCat has been created" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat has been destroyed" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rsc)
{
	if (this != &rsc)
	{
		this->_type = rsc._type;
	}
	return (*this);
}

void WrongCat::makeSound(void)const
{
	std::cout << "WrongCat making sounds" << std::endl;
}