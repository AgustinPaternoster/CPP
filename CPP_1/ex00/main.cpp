#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie*	newZombie(std::string name);
void randomChump(std::string name);

int main (void)
{
	Zombie *test;

	test = newZombie("zombie 1");
	test->announce();
	randomChump("zombie 2");

	delete test;
	return (0);
}