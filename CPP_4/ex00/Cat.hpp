#ifndef __CAT_H__
#define __CAT_H__
#include <string>
#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat(void);
		Cat(const Cat& rsc);
		~Cat(void);

		Cat& operator=(const Cat& rsc);
		void makeSound(void);
};

#endif