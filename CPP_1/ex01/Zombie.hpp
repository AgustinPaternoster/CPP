#include <string>

#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

class Zombie
{
	public:
		Zombie(void);
		Zombie(std::string const name);
		Zombie(Zombie const &rsc);
		~Zombie(void);

		Zombie & operator=(Zombie const &rsc);
		void announce(void)const;
		
		std::string getName(void)const;
		
	private:
		std::string _name;
};

Zombie*	newZombie(std::string name);
void randomChump(std::string name);

#endif