#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void):_type("n/a")
{
	std::cout << "AAnimal has been created" << std::endl;
}

AAnimal::AAnimal(std::string type): _type(type)
{
	std::cout << "AAnimal has been created" << std::endl;
}

AAnimal::AAnimal(const AAnimal& rsc)
{
	if(this != &rsc)
	{
		*this = rsc;
		std::cout << "AAnimal has been created" << std::endl;
	}
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal has been destroyed" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& rsc)
{
	if(this != &rsc)
	{
		this->_type = rsc._type;
	}
	return (*this);
}

std::string AAnimal::getType(void)const
{
	return(_type);
}