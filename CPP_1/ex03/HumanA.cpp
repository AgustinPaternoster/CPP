#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon):_name(name),weapon(weapon)
{
	std::cout << "human: " << _name << "start" << std::endl;
}

HumanA::HumanA(HumanA const & rsc):weapon(rsc.weapon)
{

}