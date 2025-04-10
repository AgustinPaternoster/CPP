#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__
#include <string>
#include "Weapon.hpp"

class HumanA
{
	public:

		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);


		void attack(void);

	private:
		std::string _name;
		Weapon& weapon;
};

#endif