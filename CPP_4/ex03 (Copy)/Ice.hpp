#ifndef __ICE_H__
#define __ICE_H__
#include "AMateria.hpp"
#include <string>

class Ice: public AMateria
{
    public:
        Ice(void);
		Ice(Ice const & other);
		~Ice(void);

		Ice& operator=(const Ice& other);
		AMateria * clone(void)const;
		void use(ICharacter& target);
		
    private:

};

#endif