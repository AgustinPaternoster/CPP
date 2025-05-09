#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

int main(void)
{

	Cat c1;
	Cat c3;
	c1.setIdea("idea 1");
	std::cout << c1.getIdea(1) << std::endl;
	Cat c2(c1);
	std::cout << c2.getIdea(1) << std::endl;
	c3 = c1;
	std::cout << c3.getIdea(1) << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;

	
	const Animal* array[6];
	
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