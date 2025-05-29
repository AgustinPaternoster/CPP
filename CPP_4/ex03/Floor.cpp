#include "Floor.hpp"
#include "iostream"

int Floor::_idx = 0;
AMateria* Floor::_descarted[100] = {0};

Floor::Floor(void){}

Floor::~Floor(void)
{
	for (int i = 0; i < _idx; i++)
		delete _descarted[i];
}

void Floor::addMateria(AMateria *unsed)
{
	if(_idx < 100)
	{	
		_descarted[_idx++] = unsed;
		std::cout << "-added to " << _idx -1 << std::endl;
	}
	else
		delete unsed;
}
