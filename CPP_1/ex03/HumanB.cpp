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
// HumanB::HumanB(Weapon const & rsc)
// {
//     _name = rsc._name;
//     weapon = rsc.weapon;
// }

void HumanB::attack(void)
{
	std::cout << _name << " attacks with their " << weapon->getType() << std::endl;
}



void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
