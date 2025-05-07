#include "FragTrap.hpp"
#include <iostream>

const int FragTrap::initHP = 100;
const int FragTrap::initEP = 100;
const int FragTrap::initAD = 30;

FragTrap::FragTrap(void)
{
	this->_hitPoints = FragTrap::initHP;
	this->_energyPoints = FragTrap::initEP;
	this->_attackDamage = FragTrap::initAD;
	std::cout << "FragTrap " << this->getName() << " is created" <<  std::endl;
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
	this->_hitPoints = FragTrap::initHP;
	this->_energyPoints = FragTrap::initEP;
	this->_attackDamage = FragTrap::initAD;
	std::cout << "FragTrap " << this->getName() << " is created" <<  std::endl;
}

FragTrap::FragTrap(const FragTrap& rhs):ClapTrap()
{
	if(this != &rhs)
	{
		std::cout << "FragTrap " << this->getName() << " is created" <<  std::endl;
		*this = rhs;
	}
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << getName() << " is destroyed" <<  std::endl;	
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

void FragTrap::attack(const std::string& target)
{
	if (_hitPoints > 0)
	{
		if (_energyPoints > 0)
		{
			std::cout << "FragTrap " << this->getName() << " attacks "
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

void FragTrap::highFivesGuys(void)
{
	std::cout << "Hey, can I get a high five?" << std::endl;
}