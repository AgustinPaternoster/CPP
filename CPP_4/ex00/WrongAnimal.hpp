#ifndef __WANIMAL_HPP__
#define __WANIMAL_HPP__
#include <string>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& rsc);
		virtual ~WrongAnimal(void);

		WrongAnimal& operator=(const WrongAnimal& rsc);
		virtual void makeSound(void)const;
		std::string getType(void)const;

	protected:
		std::string _type;
};

#endif
