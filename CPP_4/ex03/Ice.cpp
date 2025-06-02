#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice(void):AMateria("ice"){}

Ice::Ice(Ice const & other):AMateria("ice")
{
	(void)other;
}

Ice::~Ice(void){}

Ice & Ice::operator=(const Ice& other)
{
	(void)other;
	return (*this);
}

AMateria* Ice::clone(void)const
{
	return(new Ice);
}

void Ice::use(ICharacter& target)
{
        std::cout << "* shoots an ice bolt at " << target.getName()
                                << " *" << std::endl;
}
