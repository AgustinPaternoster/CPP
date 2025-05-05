#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

int main(void)
{
	const Animal *arr[4]= {new Cat(), new Dog(), new Cat(), new Dog()};

	for (int i = 0; i < 4; i++)
		arr[i]->makeSound();
	for (int i = 0; i < 4 ; i++)
		delete arr[i];
	
	return (0);
}