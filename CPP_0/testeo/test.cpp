 #include <iostream>
 #include <iomanip>

int main(void)
{
	std::string first_name = "012345678900";
	std::string last_name = "xxx";
	std::string nick_name = "yy";
	std::string phone_number = "zz";

	std::string array[4] = {first_name, last_name, nick_name, phone_number};
	std::cout << '|';
	for (int i = 0; i < 4; i++)
	{
		if (array[i].size() > 10)
			 std::cout << std::setfill('.') << std::setw(10) << std::left << array[i].substr(0,9) << "|";
		else
			std::cout << std::setw(10) << std::setfill(' ') << std::right << array[i] << "|";
	}
	std::cout << std::endl;
	return (0);
}