#ifndef __MATERIASOURCE_H__
#define __MATERIASOURCE_H__
#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& other);
		~MateriaSource(void);

		MateriaSource& operator=(const MateriaSource& other);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
		void showResources(void);
		
	private:
		AMateria*	_database[4];
		int			_idx;


};

#endif