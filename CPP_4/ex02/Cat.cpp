#include "Cat.hpp"
#include <iostream>

Cat::Cat(void):Animal("Cat"), _brain(new Brain())
{
	std::cout << "Cat has been created" << std::endl;
}

Cat::Cat(const Cat& rsc): Animal(rsc)
{
		this->_brain = new Brain();
		std::cout << "Cat has been created" << std::endl;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat has been destroyed" << std::endl;
}

Cat& Cat::operator=(const Cat& rsc)
{
	if (this != &rsc)
	{
		this->_type = rsc._type;
		this->_brain = new Brain();
	}
	return (*this);
}

void Cat::makeSound(void)const
{
	std::cout << "Cat making sounds" << std::endl;
}