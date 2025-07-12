#include <map>
#include <iostream>
#include <fstream>
#include <ctime>

// time_t parseDate()

std::string dateToString(std::tm *tmStruc)
{
	std::string date;
	date = std::to_string(tmStruc->tm_year + 1900) + "-" ;
	if (tmStruc->tm_mon < 10)
		date += "0";
	date += std::to_string(tmStruc->tm_mon + 1) + "-";
	if (tmStruc->tm_mday < 10)
		date += "0";
	date += std::to_string(tmStruc->tm_mday);
			 
	return (date);
}

bool stringToDate(std::tm *tmStruct, std::string date)
{
	int check = 0;
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

	return (true);

}



bool dataValidation(std::string date)
{
	std::tm tmStruct;
	std::time_t	rawDate;
	std::cout << stringToDate(&tmStruct, date) << std::endl;
	std::cout << dateToString(&tmStruct) << std::endl;

	rawDate = std::mktime(&tmStruct);
	return(true);
}

void _parseDate(std::string date)
{
	std::tm tmStruct;
	std::time_t	rawDate;
	stringToDate(&tmStruct, date);
}

int main(void)
{
	const char* path = "datacopy.csv";
	std::string		tmp;
	std::string		date;
	float			price;
	std::map<std::string , float> _database;
	std::string tmp2 = "2012-03-00";

	std::ifstream file(path);
	std::getline(file, tmp);
	while(std::getline(file, tmp))
	{
		date = tmp.substr(0, tmp.find(","));
		price = std::atof(tmp.substr(tmp.find(",") + 1).c_str());
		_database.insert(std::pair<std::string, float>(date,price));
		dataValidation(date);
	}

	return (0);

	
}