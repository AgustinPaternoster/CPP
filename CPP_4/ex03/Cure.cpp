#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure(void):AMateria("cure"){}

Cure::Cure(Cure const & other):AMateria("cure")
{
	(void)other;
}

Cure::~Cure(void){}

Cure & Cure::operator=(const Cure &  other)
{
	(void)other;
	return (*this);
}

AMateria* Cure::clone(void)const
{
	return(new Cure);
}

void Cure::use(ICharacter& target)
{
        std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
