#include <iostream>
#include <fstream>

int main(void)
{
	// std::ifstream	ifs("number");
	// unsigned int	dst;
	// unsigned int	dst2;
	// ifs >> dst >> dst2;

	// std::cout << dst << " " << dst2 << std::endl;
	// ifs.close();
	
	// // ------------

	// std::ofstream 	ofs("tes.out");

	// ofs << "esto es una prueba";
	// ofs.close();

	std::string  input;
	std::ifstream  file;
	file.open("test");
	file >> input;
	std::cout << file.gcount() << std::endl;
	return (0);
}