#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap ct("tester");
	ClapTrap ct3;

	ct.attack("enemy_1");
	ct.takeDamage(5);
	ct.beRepaired(3);
	ct.AttributesValues();
	ClapTrap ct2(ct);
	ct2.AttributesValues();
	ct2.beRepaired(5);
	ct2.AttributesValues();
	ct3 = ct2;
	ct3.AttributesValues();
	
	return (0);
}