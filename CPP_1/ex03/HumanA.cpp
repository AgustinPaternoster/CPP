#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon):_name(name),weapon(weapon)
{
	std::cout << "human: " << _name << " start" << std::endl;
}

HumanA::HumanA(HumanA const & rsc):weapon(rsc.weapon)
{
	this->_name = rsc._name;
}

HumanA::~HumanA(void)
{
	std::cout << "Human " << _name << " was destroyed" << std::endl;
}
void HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << weapon.getType() << std::endl;
}
