#ifndef __FRAGTRAP_H__
#define __FRAGTRAP_H__

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap& rhs);
		~FragTrap(void);

		FragTrap& operator=(const FragTrap& rhs);
		void attack(const std::string& target);
		void highFivesGuys(void);
};

#endif