#include <iostream>

int main(int arc , char** argv)
{
	std::string text;

	if (arc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < arc; i++ )
	{
		text = argv[i];
		for (int i = 0 ; i < (int)text.size() ; i++ )
		{
			if (islower(text[i]))
				std::cout << (char)toupper(text[i]);
			else
				std::cout << text[i];
		}
		
	}
	std::cout << std::endl;
	return (0);
}
