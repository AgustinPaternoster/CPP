#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void):_type("n/a")
{
	std::cout << "WrongAnimal has been created" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
	std::cout << "WrongAnimal has been created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rsc)
{
	if(this != &rsc)
	{
		*this = rsc;
		std::cout << "WrongAnimal has been created" << std::endl;
	}
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal has been destroyed" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rsc)
{
	if(this != &rsc)
	{
		this->_type = rsc._type;
	}
	return (*this);
}

void WrongAnimal::makeSound(void)const
{
	std::cout << "WrongAnimal making sounds" << std::endl;
}

std::string WrongAnimal::getType(void)const
{
	return(_type);
}