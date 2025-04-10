#include "File.hpp"
#include <iostream>

int main(int arc, char **argv)
{
	(void)arc;
	if (arc != 4)
	{	
		std::cout << "wrong numbers of arguments" << std::endl;
		return (1);
	}

	std::ifstream	infile;
	std::ofstream	outfile;
	File 			file(infile, outfile, argv[1]);
	
	if (!file.openFile())
		return (1);
	file.replace(argv[2], argv[3]);
	if (!file.saveFile())
		return (2);
	return (0);
}