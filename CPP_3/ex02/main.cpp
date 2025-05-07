#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	FragTrap ft;
	FragTrap test("tester");
	test.AttributesValues();
	test.attack("enemy");
	test.highFivesGuys();
	ft.AttributesValues();
	ft = test;
	ft.AttributesValues();
	FragTrap ft2(ft);

	return (0);
}