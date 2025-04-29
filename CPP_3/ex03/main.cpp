#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	DiamondTrap d1("diamond");
	FragTrap f1("frag");
	ClapTrap c1("clap");
	f1.takeDamage(15);
	f1.AttributesValues();
	d1.whoAmI();
	d1.AttributesValues();
	return (0);
}