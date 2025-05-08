#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void)
{			
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat(); 
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		const WrongAnimal* wanimal = new WrongCat();
		std::cout << wanimal->getType() << " " << std::endl;
		wanimal->makeSound();

		delete meta;
		delete i;
		delete j;
		delete wanimal;
		
	return (0);
}