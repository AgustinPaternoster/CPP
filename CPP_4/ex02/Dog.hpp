#ifndef __DOG_H__
#define __DOG_H__
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"
	
#include <iostream>

class Dog: public AAnimal
{
	public:
		Dog(void);
		Dog(const Dog& rsc);
		~Dog(void);

		Dog& operator=(const Dog& rsc);
		void makeSound (void)const;
		std::string getIdea(int nbIdea);
		void setIdea(std::string idea);

	private:
		Brain *_brain;
};

#endif