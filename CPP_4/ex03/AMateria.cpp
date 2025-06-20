#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria (std::string const & type):_type(type){}

AMateria::~AMateria(void){}

AMateria::AMateria(AMateria const & other):_type(other._type){}

 AMateria& AMateria::operator=(AMateria const & other)
 {
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
 }

std::string const & AMateria::getType(void)const
{
    return (_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "unknow materia is being used againts " << target.getName() << std::endl;
}