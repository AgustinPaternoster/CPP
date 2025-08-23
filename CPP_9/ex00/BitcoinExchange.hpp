#ifndef __BITCOINEXCHANGE_H__
#define __BITCOINEXCHANGE_H__
#include <map>
#include <string>
#include <ctime>

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
		class FileException : public std::exception
		{
			const char* what()const throw();
		};

		class DateException : public std::exception
		{
			public:
				DateException(std::string &msg);
				virtual ~DateException(void) throw();
				const char* what()const throw();

			private:
				std::string _errTxt;
		};

		class ValueException : public std::exception
		{
			public:
				ValueException(std::string msg);
				virtual ~ValueException(void) throw();
				const char* what() const throw();

			private:
				std::string _msg;
		};
	private:
		std::map<std::string , float> _database;
		void _parseData(std::pair<std::string, std::string>& line);
		double _exchageRate(std::string date, std::tm tmStruct);
		void _valueValidation(std::string& value);
		void _stringToDate(std::tm *tmStruct, std::string& date);
		void _checkinputfile(std::string data);
		std::string _toLower(std::string &str);
		std::string _to_string(int nb);
		std::string _dateToString(std::tm *tmStruct);
		int _stoi(std::string str);
		
};

#endif