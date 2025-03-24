#include <iostream>

class Employee
{
	
	public:
		std::string name;

		void set_salary(double amount)
		{
			if (amount <= 0)
			{
				std::cout << "The salary must be greater than 0 \n";
				salary = 0;
			}
			else
				salary = amount;
		}
	
		void get_salary(void)
		{
			std::cout << "Salary: " << salary << std::endl;
		}

		void get_bonus(void)
		{
			std::cout << "Bonus: " << calculate_bonus() << std::endl;
		}
	private:
		double salary;
	
		double calculate_bonus (void)
		{
			return salary * 0.10;
		}
	
};

int main(void)
{
	Employee employee;

	employee.name = "Agustin";
	employee.set_salary(1000);
	employee.get_salary();
	employee.get_bonus();
	return (0);
}