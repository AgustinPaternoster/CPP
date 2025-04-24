#ifndef __DIAMONDTRAP_H__
#define __DIAMONDTRAP_H__

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& rhs);
		~DiamondTrap(void);

		DiamondTrap& operator=(const DiamondTrap& rhs);
		void whoAmI(void);
	private:
		std::string _name;

};

#endif