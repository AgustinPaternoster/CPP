#include <iostream>

class Number 
{
	public:
		int n;
	Number(int set_n)
	{
		n = set_n;
	}

	Number operator+(const Number &numA)
	{
		std::cout << "this->n: " << this->n << std::endl;
		std::cout << "NumA: " << numA.n << std::endl;
		return Number(this->n + numA.n);
	}

	bool operator==(const Number& numA)
	{
		if (this->n == numA.n)
			return (true);
		return (false);
	}
};


int main(void)
{
	Number numA = 5;
	Number numB = 5;

	std::cout << "result " << (numA == numB) << std::endl;

	return (0);
}