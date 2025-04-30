#ifndef __ANIMAL_H__
#define __ANIMAL_H__
#include <string>

class Animal
{
	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal& rsc);
		~Animal(void);

		Animal& operator=(const Animal& rsc);
		void makeSound(void)const;
		std::string getType(void)const;

	protected:
		std::string _type;
};

#endif