#ifndef __AANIMAL_H__
#define __AANIMAL_H__
#include <string>

class AAnimal
{
	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(const AAnimal& rsc);
		virtual ~AAnimal(void);

		AAnimal& operator=(const AAnimal& rsc);
		virtual void makeSound(void)const = 0;
		std::string getType(void)const;

	protected:
		std::string _type;
};

#endif