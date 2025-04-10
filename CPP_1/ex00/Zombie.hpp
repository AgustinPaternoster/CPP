#include <string>

#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

class Zombie
{
	public:
		Zombie(std::string const name);
		~Zombie(void);
		void announce(void)const;
		
		std::string getName(void)const;
		
	private:
		std::string _name;
};

#endif