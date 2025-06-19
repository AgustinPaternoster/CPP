#include <string>
#include <limits>
#include <cctype>

class ScalarConverter
{
	private:
		static void setTypes(std::string &output, int& type);
		static bool isInt(std::string &output);
		static bool isFloat(std::string &output);
		static bool isdouble(std::string &output);
		static bool isChar(std::string &output);
		static bool isNon(std::string &output);
		static void convertFromInt(std::string &output);
		static void convertFromFloat(std::string &output);
		static void convertFromDouble(std::string &output);
		static void convertFromChar(std::string &output);
		static void convertFromNon(std::string &output); 
		static void printMsg(std::string type, std::string msg);
		static void printInt(int nb);
		static void printFloat(float nb);
		static void printDouble(double nb);
		static void printChar(char ch);

	public:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter(void);

		ScalarConverter& operator=(const ScalarConverter& other);
		static void convert(std::string &input);

		class NonConvertionType: public std::exception
		{
			const char* what() const throw();
		};

		static int intMax;
		static int intMin;
		static float floatMax;
		static double doubleMax;

};


