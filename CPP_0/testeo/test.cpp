 #include <iostream>

class BankAccout
{
	public:
		std::string name;
		int balance;
	void withdraw(int amount)
	{
		balance += amount;
	}

	std::string chek(void)
	{
		if (name.empty())
		{
			std::cout << "ingrese el nombre del titular: ";
			std::getline(std::cin, name);
		}
		return(name);
	}

	void print(void)
	{
		chek();
		std::cout << "Titular : " << name << std::endl;
		std::cout << "Balance : " << balance << std::endl;
	}

};

int main(void)
{
	BankAccout account1;
	BankAccout account2;

	account1.balance = 10;
	account1.print();
	return(0);
}