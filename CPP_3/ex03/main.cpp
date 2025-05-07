#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	DiamondTrap d1;
	DiamondTrap d2("diamond");
	DiamondTrap d3(d1);
	d1.whoAmI();
	d1.AttributesValues();
	d2.whoAmI();
	d2.attack("enemy");
	d2.AttributesValues();
	d3.AttributesValues();
	d1 = d2;
	d1.AttributesValues();
	return (0);
}