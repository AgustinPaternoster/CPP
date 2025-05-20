#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>
#include "Character.hpp"

int main(void)
{
    Ice ice;
	Cure cure;
	Character charac("test");
	AMateria *test[5];
	test[0] = ice.clone();
	test[1] = cure.clone(); 
	test[2] = ice.clone();
	test[3] = cure.clone(); 
	test[4] = cure.clone(); 
	for (int i = 0 ; i < 5 ; i++)
		charac.equip(test[i]);
	for (int i = 0 ; i < 5 ; i++)
		delete test[i];

    return (0);
}