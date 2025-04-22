#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
	std::cout << "derivated class is created" <<  std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "derivated class is detroyed" <<  std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& rhs):ClapTrap()
{
	if (&rhs != this)
	{
		*this = rhs;
	}
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	if(&rhs != this)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return(*this);
}

void ScavTrap::guardGate(void)
{
	std::cout <<  "ScavTrap is now in Gate keeper mode" << std::endl;
}