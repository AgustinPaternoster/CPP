#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name):_name(name)
{
    weapon = NULL;
}

HumanB::~HumanB(void)
{
    std::cout << "Human " << _name << " was destroyed" << std::endl;
}

void HumanB::attack(void)
{
	if (weapon != NULL)
		std::cout << _name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << "no weapon!" << std::endl;
}	



void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
