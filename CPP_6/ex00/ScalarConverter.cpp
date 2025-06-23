#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>


ScalarConverter::ScalarConverter(void){}

ScalarConverter::ScalarConverter(const ScalarConverter& other){(void)other;}

ScalarConverter::~ScalarConverter(void){}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}


static void printMsg(std::string type, std::string msg)
{
	std::cout << type << ": " << msg << std::endl;
}

static void printInt(int nb)
{
	std::cout << "int: " << nb << std::endl;
}

static void printFloat(float nb)
{
	std::cout << std::fixed << std::setprecision(1) << "float: " << nb  << "f" << std::endl;
}

static void printDouble(double nb)
{
	std::cout << std::fixed << std::setprecision(1) << "double: " << nb << std::endl;
}

static void printChar(char ch)
{
	std::cout << "char: " <<  "'" << ch << "'" << std::endl;
}


static bool isInt(std::string &output)
{
	char *end;
	std::strtol(output.c_str(), &end, 10);
	if (end[0] != '\0' || end == output.c_str())
		return (false);
	return (true);
}

 static bool isFloat(std::string &output)
{
	char *end;
	if (output == "nanf" || output == "+inff" || output == "inff" || output == "-inff")
		return (false);

	float i = std::strtof(output.c_str(), &end);
	(void)i;
	if (output.c_str() == end || (end[0] != 'f' || end[1] != '\0'))
		return(false);
	return (true);
}

static bool isdouble(std::string &output)
{
	char *end;
	std::size_t pos = output.find(".");
	if (pos == std::string::npos)
		return (false);
	std::strtod(output.c_str(), &end);
	if (output.c_str() == end || end[0] != '\0')
		return(false);
	return (true);
}

static bool isChar(std::string &output)
{
	if (output.length() != 1)
		return (false);
	return (true);
}

static bool isNon(std::string &output)
{
	if (output == "-inff" || output == "+inff" || output == "nanf"
		|| output == "-inf" || output == "+inf" || output == "nan"
		|| output == "inff" || output == "inf")
		return (true);
	return (false);	
}

static void convertFromInt(std::string &output)
{
	long double nb = std::strtold(output.c_str(), NULL);
	
	if (nb < 32 || nb > 126)
		printMsg("char" , "Non displayable");
	else
		printChar(static_cast<char>(nb));
	if (nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
		printMsg("int", "impossible");
	else
		printInt(static_cast<int>(nb));
	if (nb  < -std::numeric_limits<float>::max()  || nb > std::numeric_limits<float>::max())
		printMsg("float", "impossible");
	else
		printFloat(static_cast<float>(nb));
	if (nb < -std::numeric_limits<double>::max() || nb > std::numeric_limits<double>::max() )
		printMsg("double", "impossible");
	else
		printDouble(static_cast<double>(nb));
}

static void convertFromFloat(std::string &output)
{
	long double nb = std::strtold(output.c_str(), NULL);
	if (nb < 32 || nb > 126)
		printMsg("char" , "Non displayable");
	else
		printChar(static_cast<char>(nb));
	if (nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
		printMsg("int", "impossible");
	else
		printInt(static_cast<int>(nb));
	if (nb  < -std::numeric_limits<float>::max()  ||nb > std::numeric_limits<float>::max())
		printMsg("float", "impossible");
	else
		printFloat(static_cast<float>(nb));
	if (static_cast<double>(nb) < -std::numeric_limits<double>::max() || static_cast<double>(nb) > std::numeric_limits<double>::max())
		printMsg("double", "impossible");
	else
		printDouble(static_cast<double>(nb));
}

static void convertFromDouble(std::string& output)
{
	long double nb = std::strtod(output.c_str(),NULL);
	if (nb < 32 || nb > 126)
		printMsg("char" , "Non displayable");
	else
		printChar(static_cast<char>(nb));
	if (nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
		printMsg("int", "impossible");
	else
		printInt(static_cast<int>(nb));
	if (static_cast<float>(nb)  < -std::numeric_limits<float>::max()  ||static_cast<float>(nb) > std::numeric_limits<float>::max())
		printMsg("float", "impossible");
	else
		printFloat(static_cast<float>(nb));
	if (nb < -std::numeric_limits<double>::max() || nb > std::numeric_limits<double>::max())
		printMsg("double", "impossible");
	else
		printDouble(static_cast<double>(nb));
}

static void convertFromChar(std::string& output)
{
	char chr = output[0];
	if (chr < 32 || chr > 126)
		printMsg("char" , "Non displayable");
	else
		printChar(chr);
	if (chr < std::numeric_limits<int>::min() || chr > std::numeric_limits<int>::max())
		printMsg("int", "impossible");
	else
		printInt(static_cast<int>(chr));
	if (static_cast<float>(chr)  < -std::numeric_limits<float>::max()  ||static_cast<float>(chr) > std::numeric_limits<float>::max())
		printMsg("float", "impossible");
	else
		printFloat(static_cast<float>(chr));
	if (chr < -std::numeric_limits<double>::max() || chr > std::numeric_limits<double>::max())
		printMsg("double", "impossible");
	else
		printDouble(static_cast<double>(chr));
}

static void convertFromNon(std::string& output)
{
		printMsg("char", "impossible");
		printMsg("int", "impossible");
		if (output == "+inf" || output == "+inff" || output == "inf" || output == "inff" )
		{
			printMsg("float", "inff");
			printMsg("double", "inf");
		}
		if ( output == "-inf" || output == "-inff" )
		{
			printMsg("float", "-inff");
			printMsg("double", "-inf");
		}
		if ( output == "nan" || output == "nanf" )
		{
			printMsg("float", "nanf");
			printMsg("double", "nan");
		}
}

static void setTypes(std::string &output, int& type)
{
	if (isInt(output))
		type = 0;
	else if (isFloat(output))
		type = 1;
	else if (isdouble(output))
		type = 2;
	else if (isChar(output))
		type = 3;
	else if (isNon(output))
		type = 4;
}

const char* ScalarConverter::NonConvertionType::what() const throw()
{
	return("Can not convert this value");
}

void ScalarConverter::convert(std::string& output)
{
	int type = -1;
	setTypes(output,type);
	switch (type)
	{
	case 0:
		convertFromInt(output);
		break;
	case 1:
		convertFromFloat(output);
		break;
	case 2:
		convertFromDouble(output);
		break;
	case 3:
		convertFromChar(output);
		break;
	case 4:
		convertFromNon(output);
		break;
	default:
		throw ScalarConverter::NonConvertionType();
		break;
	}
}
