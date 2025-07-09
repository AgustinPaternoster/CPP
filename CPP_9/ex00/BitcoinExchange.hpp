#ifndef __BITCOINEXCHANGE_H__
#define __BITCOINEXCHANGE_H__
#include <map>
#include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(const char* path);
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange(void);

		BitcoinExchange& operator=(const BitcoinExchange& other);
		void loadDB(const char* path);
		void loadInputDB(const char* path);
		////// 
		void printData(void);
		void printData2(void);
		class FileException : public std::exception
		{
			const char* what()const throw();
		};
	private:
		std::map<std::string , float> _database;
		std::map<std::string , std::string> _input;
};

#endif