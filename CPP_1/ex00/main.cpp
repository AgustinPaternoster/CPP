#include "Zombie.hpp"
#include <iostream>
#include <string>

int main (void)
{
	Zombie *test;

	test = newZombie("zombie 1");
	test->announce();
	randomChump("zombie 2");

	delete test;
	return (0);
}