#include <string>
#include <iostream>
#include <ctime>

bool stringToDate(std::tm *tmStruct, std::string date)
{
	int check = 0;
	std::tm copy;
	for(std::string::iterator it = date.begin() ; it != date.end() ; it++)
	{
		if (*it == '-')
			check++;
	}
	if (check != 2)
		return(false);

	tmStruct->tm_year = std::stoi(date.substr(0 , date.find("-"))) - 1900;
	tmStruct->tm_mon = std::stoi(date.substr(date.find("-") + 1, date.rfind("-"))) - 1;
	tmStruct->tm_mday = std::stoi(date.substr(date.rfind("-") + 1));

	copy = *tmStruct;
	std::cout << "--" << copy.tm_mday << std::endl;
	return (true);
}

int main(void)
{
	std::string date = "2012-06-06";
	std::tm tmStruct;
	std::tm tmStruct2;
	std::time_t	rawDate;

	stringToDate(&tmStruct, date);

	std:: cout << tmStruct.tm_year + 1900 << " "
				<< tmStruct.tm_mon + 1 << " " 
				<< tmStruct.tm_mday << std::endl;
	
	tmStruct2 = tmStruct;
	rawDate = std::mktime(&tmStruct);

	std:: cout << tmStruct.tm_year + 1900 << " "
				<< tmStruct.tm_mon + 1 << " " 
				<< tmStruct.tm_mday << std::endl;
	
	if (tmStruct.tm_year == tmStruct2.tm_year && 
		tmStruct.tm_mon == tmStruct2.tm_mon &&
		tmStruct.tm_mday == tmStruct2.tm_mday)
		std::cout << "ok" << std::endl;
	else
		std::cout << "NO" << std::endl;

	return (0);
	
}