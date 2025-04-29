#ifndef __FRAGTRAP_H__
#define __FRAGTRAP_H__

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& rhs);
		~FragTrap(void);

		FragTrap& operator=(const FragTrap& rhs);
		void attack(const std::string& target);
		void highFivesGuys(void);
	
	protected:
		static const int initAD;
		static const int initEP;
		static const int initHP;
};

#endif