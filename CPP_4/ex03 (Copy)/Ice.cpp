#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice(void):AMateria("ice")
{
	// std::cout << "Ice created" << std::endl;
}

Ice::Ice(Ice const & other):AMateria("ice")
{
	(void)other;
	// std::cout << "Ice copied" << std::endl;
}

Ice::~Ice(void)
{
	// std::cout << "Ice destroyed" << std::endl;
}

Ice & Ice::operator=(const Ice& other)
{
	(void)other;
	// std::cout << "Ice copied" << std::endl;
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
