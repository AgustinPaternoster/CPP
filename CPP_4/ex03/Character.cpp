#include "Character.hpp"
#include "Floor.hpp"
#include <iostream>

Character::Character(std::string name):_name(name)
{
	for (int i = 0 ; i < 4; i++)
		_inventory[i] = NULL;
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
	}
}

Character::~Character(void)
{
	_cleanInventory();
}

Character& Character::operator=(const Character & other)
{
	if (this != &other)
        {
                this->_name = other._name;
                _cleanInventory();
                int i = 0;
                while (i < 4 && other._inventory[i] != NULL)
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
	if (m == NULL)
		return;
	for (int i = 0 ; i < 4 ; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return;
		}
	}
	std::cout << "no more free slots" << std::endl;
}

void Character::unequip(int idx)
{
	if (_inventory[idx] == NULL )
        {
                std::cout << "no materia available in slot " << idx << std::endl;
                return ;
        }
        if (idx < 0 && idx > 3)
        {
                std::cout << "idx must be between 0 and 3 " << idx << std::endl;
                return ;
        }
        Floor::addMateria(_inventory[idx]);
        _inventory[idx] = NULL;

}

void Character::use(int idx, ICharacter& target)
{

     if (idx < 0 || idx > 3 )
     {
             std::cout << "wrong idx number" << std::endl;
             return;
     }
     if (_inventory[idx] == NULL)
     {
             std::cout << "no materia available" << std::endl;
             return;
     }
     _inventory[idx]->use(target);
}                                 

void Character::showMeMaterias(void)
{
	int i = 0;
	while (i < 4 && _inventory[i] != NULL)
	{
		std::cout << "materia :" << _inventory[i]->getType() << std::endl;
		i++;
	}
}	

void Character::_cleanInventory(void)
{
		for (int i = 0 ; i < 4 ; i++)
		{
			if (_inventory[i] != NULL)
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
		}
}