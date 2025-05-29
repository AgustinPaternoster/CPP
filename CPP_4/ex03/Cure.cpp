#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure(void):AMateria("cure")
{
	std::cout << "Cure created" << std::endl;
}

Cure::Cure(Cure const & other):AMateria("cure")
{
	(void)other;
	std::cout << "Cure copied" << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "Cure destroyed" << std::endl;
}

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
        std::cout << "* heals " << target.getName() << "'s wounds" << std::endl;
}
