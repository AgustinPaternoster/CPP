#include "AAnimal.hpp"
#include <iostream>

Animal::Animal(void):_type("n/a")
{
	std::cout << "Animal has been created" << std::endl;
}

Animal::Animal(std::string type): _type(type)
{
	std::cout << "Animal has been created" << std::endl;
}

Animal::Animal(const Animal& rsc)
{
	if(this != &rsc)
	{
		*this = rsc;
		std::cout << "Animal has been created" << std::endl;
	}
}

Animal::~Animal(void)
{
	std::cout << "Animal has been destroyed" << std::endl;
}

Animal& Animal::operator=(const Animal& rsc)
{
	if(this != &rsc)
	{
		this->_type = rsc._type;
	}
	return (*this);
}

std::string Animal::getType(void)const
{
	return(_type);
}