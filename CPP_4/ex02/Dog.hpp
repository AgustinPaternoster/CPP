#ifndef __DOG_H__
#define __DOG_H__
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"
	
#include <iostream>

class Dog: public Animal
{
	public:
		Dog(void);
		Dog(const Dog& rsc);
		~Dog(void);

		Dog& operator=(const Dog& rsc);
		void makeSound (void)const;

	private:
		Brain *_brain;
};

#endif