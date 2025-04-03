#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type):_type(type)
{
	std::cout << "Weapon charged type: " << _type << std::endl;
}

Weapon::Weapon(Weapon const &rsc)
{
	this->_type = rsc._type;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon Uncharged" << std::endl;
}

Weapon & Weapon::operator=(Weapon const &rsc)
{
	this->_type = rsc._type;
	return(*this);
}

std::string const& Weapon::getType(void)
{	
	return(_type);
}

void Weapon::setType(std::string type)
{
	_type = type;
}
