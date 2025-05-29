#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Floor.hpp"
#include <iostream>
#include "Character.hpp"

int main(void)
{
    // int idx = 3;

	Character	ch1("ch1");
	// Character ch2("ch2");
	// AMateria *test[idx];
	// test[0] = new Ice();
	// test[1] = new Cure();
	// test[2] = new Cure();

	// for (int i = 0 ; i < idx ; i++)
	// 	ch1.equip(test[i]);

	// ch2.equip(new Ice());
	// ch1.showMeMaterias();
	// ch2 = ch1;
	// ch2.showMeMaterias();
	AMateria *test = new Ice();
	ch1.equip(test);
	ch1.unequip(0);
	// ch1.showMeMaterias();
	
	return (0);
}