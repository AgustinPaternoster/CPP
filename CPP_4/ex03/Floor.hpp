#include <string>
#include "AMateria.hpp"

class Floor
{
	public:
		Floor(void);
		~Floor(void);
		static void addMateria(AMateria * unsed);


	private:
		static AMateria* _descarted[100];
		static int _idx;
};