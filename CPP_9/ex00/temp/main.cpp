#include <map>
#include <iostream>
#include <fstream>
#include <ctime>

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

void stringToDate(std::tm *tmStruct, std::string date)
{
	size_t ini= date.find("-");
	size_t end =  date.rfind("-");

	std::string a = date.substr(0 , date.find("-"));
	std::string b = date.substr(date.find("-") + 1, end - ini - 1);
	std::string c = date.substr(date.rfind("-") + 1);


	tmStruct->tm_year = std::stoi(date.substr(0 , date.find("-"))) - 1900;
	tmStruct->tm_mon = std::stoi(date.substr(date.find("-") + 1, end - ini - 1)) - 1;
	tmStruct->tm_mday = std::stoi(date.substr(date.rfind("-") + 1));

}


int main(void)
{
	std::string date = "2012-12-20";
	std::tm tmStruct;
	std::time_t rawDate;
	std::tm *copy;
	stringToDate(&tmStruct, date);
	rawDate = mktime(&tmStruct);
	rawDate -= 86400;
	copy = localtime(&rawDate);
	std::cout << dateToString(copy) << std::endl;


	return (0);

	
}