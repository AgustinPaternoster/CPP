#include "Dog.hpp"
#include <iostream>

Dog::Dog(void):Animal("Dog"), _brain(new Brain())
{
	std::cout << "Dog has been created" << std::endl;
}

Dog::Dog(const Dog& rsc): Animal(rsc)
{
		std::cout << "Dog has been created" << std::endl;
		this->_brain = new Brain();
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog has been destroyed" << std::endl;
}

Dog& Dog::operator=(const Dog& rsc)
{
	if (this != &rsc)
	{
		this->_type = rsc._type;
		this->_brain = new Brain();
	}
	return (*this);
}

void Dog::makeSound(void)const
{
	std::cout << "Dog making sounds" << std::endl;
}

std::string Dog::getIdea(int nbIdea)
{
	return(_brain->getIdea(nbIdea));
}

void Dog::setIdea(std::string idea)
{
	_brain->setIdea(idea);
}
