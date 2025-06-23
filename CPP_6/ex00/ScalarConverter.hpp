#include <string>
#include <limits>
#include <cctype>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter(void);
		ScalarConverter& operator=(const ScalarConverter& other);

	public:
		static void convert(std::string &input);
		class NonConvertionType: public std::exception
		{
			const char* what() const throw();
		};
};


