#include "Dog.hpp"
#include <iostream>

Dog::Dog(void):Animal("Dog")
{
	std::cout << "Dog has been created" << std::endl;
}

Dog::Dog(const Dog& rsc): Animal(rsc)
{
		std::cout << "Dog has been created" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog has been destroyed" << std::endl;
}

Dog& Dog::operator=(const Dog& rsc)
{
	if (this != &rsc)
	{
		this->_type = rsc._type;
	}
	return (*this);
}

void Dog::makeSound(void)const
{
	std::cout << "Dog making sounds" << std::endl;
}