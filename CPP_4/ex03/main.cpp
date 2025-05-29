#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>
#include "Character.hpp"
#include "Floor.hpp"

int main(void)
{
    // int idx = 3;

	// Floor fl1;	
	// Character ch1("ch1");
	ICharacter *ch2; 
	// // AMateria *test[idx];
	// test[0] = new Ice();
	// // test[1] = new Cure();
	// // test[2] = new Cure();
	
	// // for (int i = 0 ; i < idx ; i++)
	// // 	ch1.equip(test[i]);
	// // ch1.showMeMaterias();
	// // ch2 = ch1;
	// // ch2.showMeMaterias();
	// ch1.equip(new Cure());
	// ch1.equip(new Ice());
	ch2 = new Character ("ch2");
	ch2->equip(new Cure());
	// ch1.showMeMaterias();
	// ch1.use(1, *ch2);
	delete ch2;
    // return (0);
}