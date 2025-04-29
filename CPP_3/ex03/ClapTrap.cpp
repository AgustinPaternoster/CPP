#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):_name("n/a"),
_hitPoints(0) , _energyPoints(0) , _attackDamage(0)
{
	std::cout << "ClapTrap " << getName() << " is created" <<  std::endl;
}

ClapTrap::ClapTrap(std::string name):_name(name),
_hitPoints(10) , _energyPoints(10) , _attackDamage(0)
{
	std::cout << "ClapTrap " << getName() << " is created" <<  std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << getName() << " is destroyed" <<  std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
		this->_hitPoints	= rhs._hitPoints;
	}
	return (*this);
}

std::string ClapTrap::getName(void)const
{
	return (this->_name);
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints > 0)
	{
		if (_energyPoints > 0)
		{
			std::cout << "ClapTrap " << this->getName() << " attacks "
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

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >_hitPoints)
	{
		_hitPoints = 0;
		std::cout << this->getName() << " are death" << std::endl; 
	}
	else
	{
		std::cout << this->getName() << " was attacked, taking "
				    << amount << " of hit points" << std::endl;
		_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints  > 0)
	{
		std::cout << getName() << " get " << amount << " hit points" << std::endl;
		_energyPoints--;
		_hitPoints += amount;
	}
	else
		std::cout << this->getName() << " have no energy points" << std::endl; 
}

void ClapTrap::AttributesValues(void)
{
	std::cout << "name:" << this->getName() << std::endl
			  << "_hitpoints: " << _hitPoints << std::endl
			  << "_energy Points: " << _energyPoints << std::endl
			  << "_attack damage: " << _attackDamage << std::endl;
}