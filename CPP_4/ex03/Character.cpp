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
	// completar
	std::cout << "character " << _name << " copied" << std::endl;
}

Character::~Character(void)
{
	//completar
	std::cout << "character " << _name << " destroyed" << std::endl;
}

Character& Character::operator=(const Character & other)
{
	(void)other;
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