#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <string>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& rhs);
		~ClapTrap(void);

		ClapTrap& operator=(const ClapTrap& rhs);

		std::string getName(void)const;
		void AttributesValues(void);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);



	protected:
		std::string 	_name;
		unsigned int	_hitPoints;
		unsigned int 	_energyPoints;
		unsigned int	_attackDamage;
};
#endif
