#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap st;
	ScavTrap test("tester");
	test.AttributesValues();
	test.attack("enemy");
	test.guardGate();
	st.AttributesValues();
	st = test;
	st.AttributesValues();
	ScavTrap st2(st);
	return (0);
}