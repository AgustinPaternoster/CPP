#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"
class Character: public ICharacter
{
	public:
		Character(std::string name);
		Character(const Character & other);
		~Character(void);

		Character& operator=(const Character& other);
		std::string const& getName(void)const;
		void equip(AMateria* m);
		void unequip(int idx);
		// void use(int idx, ICharacter& target);
		void showMeMaterias(void);

	private:
		AMateria* 	_inventory[4];
		std::string _name;
		void _cleanInventory(void);
};

#endif