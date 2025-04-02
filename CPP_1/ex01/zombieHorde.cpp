#include "Zombie.hpp"
#include <string>

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return (NULL);

	Zombie *array;
	array =  new Zombie[N];
	for(int i = 0 ; i < N ; i++)
		array[i].setName(name);
	return (array);
}