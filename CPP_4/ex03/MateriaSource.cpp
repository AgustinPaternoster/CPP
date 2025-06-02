#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

MateriaSource::MateriaSource(void):_idx(0)
{
	for (int i = 0; i < 4; i++)
		_database[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other):_idx(other._idx)
{
	for (int i = 0; i < other._idx; i++)
	{
		_database[i] = other._database[i]->clone();
	}
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < _idx; i++)
		delete _database[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if(this != &other)
	{
		for(int i = 0; i < this->_idx; i++)
			delete this->_database[i];
		this->_idx = other._idx;
		for(int i = 0; i < other._idx; i++)
			this->_database[i] = other._database[i]->clone();
	}
	return(*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (_idx > 3)
	{
		std::cout << "no slot available" << std::endl;
		delete materia;
		return;
	}
	_database[_idx++] = materia;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for(int i = 0; i < _idx; i++)
	{
		if (!type.compare(_database[i]->getType()))
			return (_database[i]->clone());
	}
	std::cout << "no coincidence found" << std::endl;
	return (NULL);
}

void MateriaSource::showResources(void)
{
	for (int i = 0; i < _idx; i++)
		std::cout << _database[i]->getType() << std::endl;
}