#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria (std::string const & type):_type(type)
{
    std::cout << "Materia creates" << std::endl;
}

AMateria::~AMateria(void)
{
    std::cout << "materia destroyed" << std::endl;
}

std::string const & AMateria::getType(void)const
{
    return (_type);
}