#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__
#include <string>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    private:
        ScavTrap(void);
        ScavTrap(const ScavTrap& rhs);
        ~ScavTrap(void);

        ScavTrap& operator=(const ScavTrap& rhs);
        void guardGate(void);        

    public:

};

#endif