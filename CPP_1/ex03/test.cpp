#include <iostream>
class Test
{
	public:
		Test(std::string txt):txtt(txt){}
		std::string const &get()
		{
			return (txtt);
		}
		
	private:
		std::string txtt;

};


int main(void)
{
	Test tester;

	std::string const &ref = tester.get();
	
	std::cout << tester.get() << std::endl;
	std::cout << "ref:" << ref << std::endl;
	std::cout << tester.get() << std::endl;
	std::cout << "ref:" << ref << std::endl;
	

	return (0);
}