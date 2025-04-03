#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__
#include <string>
#include "Weapon.hpp"

class HumanA
{
	public:

		HumanA(std::string name, Weapon& weapon);
		HumanA(HumanA const & rsc);
		~HumanA(void);

		//HumanA & operator=(HumanA const & rsc);

		void attack(void);

	private:
		std::string _name;
		Weapon& weapon;
};

#endif