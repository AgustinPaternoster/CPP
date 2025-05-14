#ifndef __AMATERIA_H__
#define __AMATERIA_H__
#include <string>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        // [...]
    public:
        AMateria(std::string const & type);
        // [...]
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif