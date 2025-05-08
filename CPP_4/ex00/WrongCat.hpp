#ifndef __WCAT_H__
#define __WCAT_H__

#include <string>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat& rsc);
		~WrongCat(void);

		WrongCat& operator=(const WrongCat& rsc);
		void makeSound(void)const;
};

#endif