#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap ct("tester");
	
	ct.attack("enemy_1");
	ct.takeDamage(5);
	ct.beRepaired(3);
	
	
	ClapTrap ct_1(ct);
	ct_1.AttributesValues();


	
	return (0);
}