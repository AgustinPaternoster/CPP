#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

int main(void)
{
	
	// AAnimal an;
	
	const AAnimal* array[6];
	
	for (int i = 0; i < 6; i++)
	{
		if(i % 2 == 0)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}

	for (int i = 0; i < 6; i++)
		array[i]->makeSound();
	
	for (int i = 0; i < 6; i++)
		delete array[i];
	
	return (0);
}