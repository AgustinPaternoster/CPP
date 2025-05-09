#ifndef __CAT_H__
#define __CAT_H__
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
{
	public:
		Cat(void);
		Cat(const Cat& rsc);
		~Cat(void);

		Cat& operator=(const Cat& rsc);
		void makeSound(void)const;

	private:
		Brain *_brain;
};

#endif