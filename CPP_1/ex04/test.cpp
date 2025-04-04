#include <iostream>
#include <string>
#include <fstream>

int main(void)
{
	std::ifstream txt;
	std::ofstream out;
	//std::string buffer;
	txt.open("test");	
	std::string str;
	txt.seekg(0, txt.end);
	int size = txt.tellg();
	txt.seekg(0,txt.beg);

	char buffer[size + 1];
	buffer[size] = '\0';
	std::string s1 = "es una";
	std::string s2 = "XXXX";

	txt.read(buffer, size);
	str = buffer;
	
	// std::cout << str << std::endl;
	
	int i = 0;
	int found = 0;
	while (found >= 0)
	{
		found = str.find(s1, found+i);
		if (found >= 0)
		{
			str.erase(found, s1.size());
			str.insert(found,s2);			
		}	
		
	}
	out.open("testt");
	const char * tmp = str.c_str();
	out.write(tmp, str.size());

}