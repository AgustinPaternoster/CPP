#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

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
	float			price;

	std::ifstream file(path);
	if (!file.is_open())
		throw BitcoinExchange::FileException();
	std::getline(file, tmp);
	while(std::getline(file, tmp))
	{
		date = tmp.substr(0, tmp.find(","));
		price = std::atof(tmp.substr(tmp.find(",") + 1).c_str());
		_database.insert(std::pair<std::string, float>(date,price));
	}
}

void BitcoinExchange::printData(void)
{
	for(std::map<std::string, float>::iterator it = _database.begin(); it != _database.end(); it++)
	{
		std::cout << it->first << " - " << it->second << std::endl;
	}
}

void BitcoinExchange::printData2(void)
{
	for(std::map<std::string, std::string>::iterator it = _input.begin(); it != _input.end(); it++)
	{
		std::cout << it->first << " - " << it->second << std::endl;
	}
}

void BitcoinExchange::loadInputDB(const char* path)
{
	std::string tmp;
	std::ifstream file(path);
	if(!file.is_open())
		throw BitcoinExchange::FileException();
	std::getline(file, tmp);
	while(std::getline(file, tmp))
	{
		std::string date = tmp.substr()
	}
}

const char* BitcoinExchange::FileException::what()const throw()
{
	return ("Error opening file");
}