#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__
	#include <string>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    public:
		ScavTrap(void);
        ScavTrap(std::string name);
		ScavTrap(const ScavTrap& rhs);
        ~ScavTrap(void);

        ScavTrap& operator=(const ScavTrap& rhs);
		void attack(const std::string& target);
        void guardGate(void);        
};

#endif