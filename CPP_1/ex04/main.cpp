#include "File.hpp"
#include <iostream>

int main(int arc, char **argv)
{
	(void)arc;
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