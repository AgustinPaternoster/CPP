#include "Character.hpp"
#include <iostream>

Character::Character(std::string name):_name(name)
{
	for (int i = 0 ; i < 3; i++)
		_inventory[i] = NULL;
	std::cout << "character " << name << " created" << std::endl;
}

Character::Character(const Character& other):_name(other._name)
{
	if (this != &other)
	{
		for (int i = 0 ; i < 3; i++)
		{	
			if (other._inventory[i] != NULL)
				this->_inventory[i] = other._inventory[i]->clone();	
			else		
				_inventory[i] = NULL;
		}	
		std::cout << "character " << _name << " copied" << std::endl;
	}
}

Character::~Character(void)
{
	int i = 0;
	while (i < 3 && _inventory[i] != NULL)
	{
		delete _inventory[i];
		i++;
	}
	std::cout << "character " << _name << " destroyed" << std::endl;
}

Character& Character::operator=(const Character & other)
{
	if (this != &other)
	{
		this->_name = other._name;
		int i = 0;
		while (i < 3 && other._inventory[i] != NULL)
		{
			this->_inventory[i] = other._inventory[i]->clone(); 
			i++;
		}
	}
	return(*this);
}

std::string const& Character::getName(void)const
{
	return(_name);
}

void Character::equip(AMateria * m)
{
	for (int i = 0 ; i < 4 ; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << "materia added in slot: " << i << std::endl;
			return;
		}
	}
	std::cout << "no more free slots" << std::endl;
}

void Character::unequip(int idx)
{
	(void)idx;
	// conmpletar
}

void Character::use(int idx, ICharacter& target)
{
	(void)idx;
	(void)target;
	// copletar
}

void Character::showMeMaterias(void)
{
	int i = 0;
	while (i < 3 && _inventory[i] != NULL)
	{
		std::cout << "materia :" << _inventory[i]->getType() << std::endl;
		i++;
	}
}	
