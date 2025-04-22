#include <iostream>

class Padre
{
	public:
		void printnb(void)
		{
			std::cout << "numero:" << nb << std::endl;
		}
		void printkey(void)
		{
			std::cout << "clave:" << _clave << std::endl;
		}
		void setKey(int key)
		{
			_clave = key;
		}
		int nb;
	private:
		int _clave = 42;
};

class Hijo: public Padre
{
	public:
		std::string categ;
};

int main(void)
{
	Padre p1;
	p1.nb = 10;
	Hijo h1;
	h1.printkey();
	h1.setKey(123);
	h1.printkey();
	p1.printkey();


	
	return (0);
}