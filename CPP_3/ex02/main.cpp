#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	FragTrap testf("frag");
	ScavTrap tests("scrav");
	testf.AttributesValues();
	tests.AttributesValues();

	return (0);
}