#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap test("tester");
	test.AttributesValues();
	test.attack("enemy");
	test.AttributesValues();
	test.takeDamage(24);
	test.AttributesValues();
	test.beRepaired(10);
	test.AttributesValues();
	test.guardGate();
	return (0);
}