#include <string>

#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);
		Zombie(std::string const name);

		void announce(void)const;
		
		std::string getName(void)const;
		void setName(std::string name);
		
	private:
		std::string _name;
};

Zombie*	newZombie(std::string name);
void randomChump(std::string name);

#endif