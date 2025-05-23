#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void):ClapTrap("n/a_clap_name") ,
	ScavTrap() ,FragTrap()
{
	this->_name = "n/a";
	this->_hitPoints = FragTrap::initHP;
	this->_energyPoints = ScavTrap::initEP;
	this->_attackDamage = FragTrap::initAD;
	std::cout << "DiamondTrap " << this->getName() << " is created" <<  std::endl;
}

DiamondTrap::DiamondTrap(std::string name):ClapTrap(name + "_clap_name") ,
	ScavTrap(name) ,FragTrap(name)
{
	this->_name = name;
	this->_hitPoints = FragTrap::initHP;
	this->_energyPoints = ScavTrap::initEP;
	this->_attackDamage = FragTrap::initAD;
	std::cout << "DiamondTrap " << this->getName() << " is created" <<  std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs): ClapTrap(rhs._name + "_clap_name") ,
	ScavTrap(rhs._name + "_clap_name") ,FragTrap(rhs._name + "_clap_name")
{
	if (this != &rhs)
	{
		*this = rhs;
	}
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->getName() << " is destroyed" <<  std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	if(this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return(*this);
}

std::string DiamondTrap::getName(void)const
{
	return (this->_name);
}

void DiamondTrap::AttributesValues(void)
{
	std::cout << "name:" << this->getName() << std::endl
	<< "_hitpoints: " << _hitPoints << std::endl
	<< "_energy Points: " << _energyPoints << std::endl
	<< "_attack damage: " << _attackDamage << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->getName() << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::getName() << std::endl;
	
}