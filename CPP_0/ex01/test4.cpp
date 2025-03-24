#include <iostream>

class Sample 
{
	public:
		Sample(void);
		~Sample(void);

		int		getFoo(void) const;
		void	compare(Sample * other);
	
		private:

			int _foo;
};

Sample::Sample(void)
{
	std::cout << "Inicion de la clase" << std::endl;
}
Sample::~Sample(void)
{
	std::cout << "Fin de la clase" << std::endl;
}

int Sample::getFoo(void)const
{
	return this->_foo;
}

void Sample::sefFoo(int v)
{
	if (v > 0)
		this->_foo = v;
}

int main(void)
{
	
	Sample test;
	test.sefFoo(20);
	std::cout << test.getFoo() << std::endl;
	
	return (0);
}