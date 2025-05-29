#ifndef __CURE_H__
#define __CURE_H__
#include "AMateria.hpp"
#include <string>

class Cure: public AMateria
{
    public:
        Cure(void);
		Cure(Cure const & other);
		~Cure(void);

		Cure & operator=(const Cure & other);
		AMateria * clone(void)const;
		void use(ICharacter& target);

    private:

};

#endif