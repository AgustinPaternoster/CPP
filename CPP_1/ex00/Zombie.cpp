#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(void):_name("")
{
	std::cout << "new zombie" << std::endl;
}

Zombie::Zombie(std::string const name):_name(name)
{
	std::cout << "new zombie named " << getName() << std::endl;
}

Zombie::Zombie(Zombie const &rsc)
{
	_name = rsc.getName();
}

Zombie & Zombie::operator=(Zombie const &rsc)
{
	if (this !=&rsc)
		_name = rsc.getName();
	
	return (*this);
}

std::string Zombie::getName(void)const
{
	return (_name);
}

Zombie::~Zombie(void)
{
	std::cout << getName() << " has died" << std::endl;
}

void Zombie::announce(void)const
{
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
