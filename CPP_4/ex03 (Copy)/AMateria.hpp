#ifndef __AMATERIA_H__
#define __AMATERIA_H__
#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria(std::string const & type);
        AMateria(AMateria const & other);
        virtual ~AMateria(void);

        AMateria & operator=(AMateria const & other);
        // [...]
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif