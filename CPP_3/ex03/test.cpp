#include <iostream>

class base
{
	public:
		base(void):_name("n/a")
		{
			std::cout << "base constructor " << this->_name << std::endl;
		}
		base(std::string name):_name(name)
		{
			std::cout << "base constructor " << this->_name << std::endl;
		}
		~base(void)
		{
			std::cout << "base destructor " << this->_name << std::endl;

		}


	protected:
		std::string _name;
};

class child_b1: virtual public base
{
	public:
		child_b1(void)
		{
			_name = "n/a";
			std::cout << "child_b1 cosntructor " << this->_name << std::endl;

		}
		child_b1(std::string name)
		{
			_name = name;
			std::cout << "child_b1 cosntructor " << this->_name << std::endl;

		}
		~child_b1(void)
		{
			std::cout << "child_b1 destructor " << this->_name << std::endl;

		}

};

class child_b2: virtual public base
{
	public:
		child_b2(void)
		{
			_name = "n/a";
			std::cout << "child_b2 cosntructor " << this->_name << std::endl;

		}
		child_b2(std::string name)
		{
			_name = name;
			std::cout << "child_b2 cosntructor " << this->_name << std::endl;

		}
		~child_b2(void)
		{
			std::cout << "child_b2 destructor " << this->_name << std::endl;

		}

};

class derivated : public child_b1 , public child_b2
{
	public:
		derivated(std::string name) : base(name + "xxx"),_name(name)
		{
			std::cout << "derivada cosntructor " << this->_name << std::endl;
		}
		~derivated(void)
		{
			std::cout << "derivada destructor " << this->_name << std::endl;
		}
	
	private:
		std::string _name;
};

int main(void)
{
	derivated test("hola");
	return (0);
}