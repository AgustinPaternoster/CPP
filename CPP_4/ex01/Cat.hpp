#ifndef __CAT_H__
#define __CAT_H__
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"
class Cat: public Animal
{
	public:
		Cat(void);
		Cat(const Cat& rsc);
		~Cat(void);

		Cat& operator=(const Cat& rsc);
		void makeSound(void)const;
		std::string getIdea(int nbIdea);
		void setIdea(std::string idea);

	private:
		Brain *_brain;
};

#endif