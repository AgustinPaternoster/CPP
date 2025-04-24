#include <iostream>

class base
{
	public:
		base(void):i(10)
		{
			std::cout << "base constructor" << std::endl;
		}
		base(int nb):i(nb)
		{
			std::cout << "base constructor" << std::endl;
		}

	protected:
		int i;
};

class child_b1: virtual public base
{
	public:
		child_b1(void)
		{
			this->i = 30;
			std::cout << "child_b1 constructor" << std::endl;
		}

};

class child_b2: virtual public base
{
	public:
		child_b2(void)
		{
			this->i = 50;
			std::cout << "child_b2 constructor" << std::endl;
		}

};

class derivated : public child_b1 , public child_b2
{
	public:
		derivated(int n) : base(0)
		{
			this->i = n;
		}
	
	private:
		int i;
};

int main(void)
{
	derivated test(10);
	return (0);
}