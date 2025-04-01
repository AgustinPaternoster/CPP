 #include <iostream>
 #include <iomanip>

class Sample
{
	public:

	Sample(void);
	Sample(int const n);
	Sample(Sample const & src);
	~Sample(void);

	Sample & operator=(Sample const & rhs);

	int getFoo(void)const
	{
		return(_foo);
	}

	private:

		int _foo;	
};

Sample::Sample(void):_foo(0)
{
	std::cout << "Default constructor called" << std::endl;

	return;
}

Sample::Sample(int const n):_foo(n)
{
	std::cout << "Paramatric contructor caled" << std::endl;
	return;
}
Sample::Sample(Sample const & src)
{
	std::cout << "copy contructor called" << std::endl;
	*this = src;

	return;
}

Sample::~Sample(void)
{
	std::cout << "destructor called" << std::endl;
}

Sample& Sample::operator=(Sample const & rhs)
{
	
}

int main(void)
{
	Sample intance1;
	Sample intance2(42);
	Sample intance3(intance1);

	std::cout << intance1.getFoo();
	std::cout << intance2.getFoo();
	std::cout << intance3.getFoo();

	intance3 = intance2;
	std::cout << intance3.getFoo() << std::endl;
	return (0);
}