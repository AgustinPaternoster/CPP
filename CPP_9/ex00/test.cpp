#include <map>
#include <iostream>
#include <fstream>

int main(void)
{
	std::ifstream file;
	file.open("./data copy.csv");
	std::string data;
	
	std::map<std::string, float> database;

	std::getline(file, data);


	// std::cout << data.substr(0, data.find(",")) << std::endl;
	// std::cout << std::stof(data.substr(data.find(",") + 1)) << std::endl;
	
	while (std::getline(file, data))
	{
		std::string date = data.substr(0, data.find(","));
		// float		price = std::stof(data.substr(data.find(",") + 1));
		float		price = std::atof(data.substr(data.find(",") + 1).c_str());

		database.insert(std::pair<std::string, float>(date, price));
	}
	for (std::map<std::string, float>::iterator it = database.begin() ; it != database.end() ; it++ )
		std::cout << it->first << " - " << it->second << std::endl;
	
	std::cout << "size: " << database.size() << std::endl;
	
	return (0);

	
}