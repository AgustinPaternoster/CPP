#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <limits>

BitcoinExchange::BitcoinExchange(void){}
BitcoinExchange::BitcoinExchange(const char* path)
{
	loadDB(path);
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->_database = other._database;
}
BitcoinExchange::~BitcoinExchange(void){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		this->_database = other._database;
	return (*this);
}

void BitcoinExchange::loadDB(const char* path)
{
	std::string		tmp;
	std::string		date;
	double			price;

	std::ifstream file(path);
	if (!file.is_open())
		throw BitcoinExchange::FileException();
	std::getline(file, tmp);
	while(std::getline(file, tmp))
	{
		date = tmp.substr(0, tmp.find(","));
		price = std::atof(tmp.substr(tmp.find(",") + 1).c_str());
		_database.insert(std::pair<std::string, double>(date,price));
	}
	file.close();
}

void BitcoinExchange::loadInputDB(const char* path)
{
	std::string 						data;
	size_t 								pos;
	std::pair<std::string,std::string>	line;
	
	std::ifstream file(path);
	if(!file.is_open())
		throw BitcoinExchange::FileException();
	std::getline(file, data);
	while (std::getline(file, data))
	{
		pos = data.find(" | ");
		if (pos == std::string::npos)
		{
			line.first = data;
			line.second = "";
		}
		else
		{
			line.first = data.substr(0, pos);
			line.second = data.substr(pos + 3);
		}
		_parseData(line);
	}
	file.close();	
}

void BitcoinExchange::_parseData(std::pair<std::string, std::string>& line)
{
	std::tm	tmStruct;
	double	exchRate;
	
	try
	{
		_stringToDate(&tmStruct, line.first);
		_valueValidation(line.second);
		exchRate =  _exchageRate(line.first, tmStruct);
		std::cout << line.first << "=> " << line.second 
				  << " = " << std::atof(line.second.c_str()) * exchRate 
				  << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void BitcoinExchange::_stringToDate(std::tm *tmStruct, std::string& date)
{
	int check = 0;
	std::tm copy;
	std::time_t t_tmp;
	std::time_t today;

	for(std::string::iterator it = date.begin() ; it != date.end() ; it++)
	{
		if (*it == '-')
			check++;
	}
	if (check != 2 || date.size() != 10)
		throw BitcoinExchange::DateException(date);

	tmStruct->tm_year = _stoi(date.substr(0 , date.find("-"))) - 1900;
	tmStruct->tm_mon = _stoi(date.substr(date.find("-") + 1, 2)) - 1;
	tmStruct->tm_mday = _stoi(date.substr(date.rfind("-") + 1));
	copy = *tmStruct;
	t_tmp = std::mktime(tmStruct);
	if (tmStruct->tm_year != copy.tm_year && tmStruct->tm_mon != copy.tm_mon 
		&& tmStruct->tm_mday != copy.tm_mday)
			throw BitcoinExchange::DateException(date);
	copy.tm_year = 2009 - 1900;
	copy.tm_mon = 0;
	copy.tm_mday = 2;
	if (t_tmp < std::mktime(&copy) || t_tmp > std::time(&today))
		throw BitcoinExchange::DateException(date);
}

int BitcoinExchange::_stoi(std::string str)
{
	std::stringstream ss(str);
	int num;
	ss >> num;
	return (num);
}

void BitcoinExchange::_valueValidation(std::string& value)
{
	std::stringstream ss(value);
	double fvalue;
	ss >> fvalue;
	if (ss.fail() || !ss.eof() )
		throw BitcoinExchange::ValueException("Error: invalid number");
	if (fvalue <= 0)
		throw BitcoinExchange::ValueException("Error: not a positive number");
	if (std::numeric_limits<int>::max() < fvalue)
		throw BitcoinExchange::ValueException("Error: too large a number");
}

double BitcoinExchange::_exchageRate(std::string date, std::tm tmStruct)
{
	std::tm *tmStructCopy;
	std::time_t rawTime = std::mktime(&tmStruct);
	unsigned int check = _database.count(date);
	while (!_database.count(date))
	{
		rawTime -=  86400;
		tmStructCopy = std::localtime(&rawTime);
		date = _dateToString(tmStructCopy);
	}
	(void)check;
	return (_database.find(date)->second);
}

std::string BitcoinExchange::_to_string(int nb)
{
	std::stringstream oss;
	oss << nb;
	return (oss.str());
}

std::string BitcoinExchange::_dateToString(std::tm *tmStruct)
{
	std::string date;
	date = _to_string(tmStruct->tm_year + 1900) + "-" ;
	if (tmStruct->tm_mon < 10)
		date += "0";
	date += _to_string(tmStruct->tm_mon + 1) + "-";
	if (tmStruct->tm_mday < 10)
		date += "0";
	date += _to_string(tmStruct->tm_mday);
			 
	return (date);
}

void BitcoinExchange::_checkinputfile(std::string data)
{
		size_t pos  = data.find(" | ");
		if (pos == std::string::npos)

		else
		{
			line.first = data.substr(0, pos);
			line.second = data.substr(pos + 3);
		}
}
const char* BitcoinExchange::FileException::what()const throw()
{
	return ("Error opening file");
}

BitcoinExchange::DateException::DateException(std::string &msg)
	:_errTxt("Error: bad input => " + msg){}

BitcoinExchange::DateException::~DateException(void)throw(){}

const char* BitcoinExchange::DateException::what()const throw()
{
	return(_errTxt.c_str());  
}

BitcoinExchange::ValueException::ValueException(std::string msg)
:_msg(msg){}

BitcoinExchange::ValueException::~ValueException(void) throw(){}

const char* BitcoinExchange::ValueException::what() const throw()
{
	return(_msg.c_str());
}