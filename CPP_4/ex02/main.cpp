#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

int main(void)
{
	
	// AAnimal an;

	Cat c1;
	Dog d1;

	c1.makeSound();
	std::cout << c1.getIdea(1) << std::endl;
	d1.makeSound();
	

	// Cat c1;
	// Cat c3;
	// c1.setIdea("idea 1");
	// std::cout << c1.getIdea(1) << std::endl;
	// Cat c2(c1);
	// std::cout << c2.getIdea(1) << std::endl;
	// c3 = c1;
	// c1.setIdea("idea 2");
	// std::cout << c1.getIdea(2) << std::endl;
	// std::cout << c3.getIdea(1) << std::endl;
	// std::cout << c3.getIdea(2) << std::endl;
	// std::cout << "-----------------------------------------------------" << std::endl;

	// Dog d1;
	// Dog d3;
	// d1.setIdea("idea 1");
	// std::cout << d1.getIdea(1) << std::endl;
	// Dog d2(d1);
	// std::cout << d2.getIdea(1) << std::endl;
	// d3 = d1;
	// d1.setIdea("idea 2");
	// std::cout << d1.getIdea(2) << std::endl;
	// std::cout << d3.getIdea(1) << std::endl;
	// std::cout << d3.getIdea(2) << std::endl;
	// std::cout << "-----------------------------------------------------" << std::endl;
	// const AAnimal* array[6];
	

	// for (int i = 0; i < 6; i++)
	// {
	// 	if(i % 2 == 0)
	// 		array[i] = new Dog();
	// 	else
	// 		array[i] = new Cat();
	// }

	// for (int i = 0; i < 6; i++)
	// 	array[i]->makeSound();
	
	// for (int i = 0; i < 6; i++)
	// 	delete array[i];
	
	return (0);
}