#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void)
{			
		 Animal* meta = new Animal();
		 Animal* j = new Dog();
		 Animal* i = new Cat(); 

		//const Animal* tmp;
		//tmp = i;
		*i = *j;
		std::cout << i->getType() << std::endl;

		delete meta;
		//delete tmp;
		delete i;
		delete j;

		
	return (0);
}