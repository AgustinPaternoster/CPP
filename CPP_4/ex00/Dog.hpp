#ifndef __DOG_H__
#define __DOG_H__
#include <string>
#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog(void);
		Dog(const Dog& rsc);
		~Dog(void);

		Dog& operator=(const Dog& rsc);
		void makeSound (void)const;
};

#endif