#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie* zombieHorde( int N, std::string name );

int main (void)
{
	Zombie * firstZombie;
	
	firstZombie = zombieHorde(5,"tester");
	for (int i = 0 ; i < 5; i++)
		firstZombie[i].announce();

	delete []firstZombie;
	return (0);
}