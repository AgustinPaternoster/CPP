#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

const int ScavTrap::initAD = 20;
const int ScavTrap::initEP = 50;
const int ScavTrap::initHP = 100;

ScavTrap::ScavTrap(void)
{
	this->_hitPoints = ScavTrap::initHP;
	this->_energyPoints = ScavTrap::initEP;
	this->_attackDamage = ScavTrap::initAD;
	std::cout << "ScavTrap " << this->getName() << " is created" <<  std::endl;
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
	this->_hitPoints = ScavTrap::initHP;
	this->_energyPoints = ScavTrap::initEP;
	this->_attackDamage = ScavTrap::initAD;
	std::cout << "ScavTrap " << this->getName() << " is created" <<  std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << getName() << " is destroyed" <<  std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& rhs):ClapTrap()
{
	if (&rhs != this)
	{
		std::cout << "ScavTrap " << this->getName() << " is created" <<  std::endl;
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
	if (this->_hitPoints > 0)
		std::cout <<  "ScavTrap is now in Gate keeper mode" << std::endl;
	else
		std::cout <<  "Don't have energy points" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints > 0)
	{
		if (_energyPoints > 0)
		{
			std::cout << "ScavTrap " << this->getName() << " attacks "
					<< target << ", causing " << _attackDamage << " points of damage!"
					<< std::endl; 
			_energyPoints--;
		}
		else
		{
			std::cout << this->getName() << " have no energy points" << std::endl; 
		}
	}
	else
		std::cout << this->getName() << " are death" << std::endl; 
}