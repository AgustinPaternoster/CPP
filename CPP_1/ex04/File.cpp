#include "File.hpp"
#include <iostream>

File::File(std::ifstream& infile, std::ofstream& outfile, std::string fname)
	:_infile(infile), _outfile(outfile), _filename(fname){};

File::~File(void)
{
	std::cout << "File close" <<  std::endl;
}

bool File::openFile(void)
{
	int size;

	
	_infile.open(_filename.c_str());
	if (_infile.is_open())
	{
		_infile.seekg(0, _infile.end);
		size = _infile.tellg();
		_infile.seekg(0, _infile.beg);
		char buffer[size + 1];
		_infile.read(buffer, size);
		buffer[size] = '\0';
		_text = buffer;
		_infile.close();
		return (true);
	}
	else
	{
		std::cout << "Failed to open the file: " << _filename << std::endl;
		return (false);
	}

}

void File::replace(std::string s1, std::string s2)
{
	int	i;
	int found;

	i = 0;
	found = 0;
	while(found >= 0)
	{
		found = _text.find(s1, found + i);
		if (found >= 0)
		{
			_text.erase(found, s1.size());
			_text.insert(found, s2);
		}
		i++;
	}
}

bool File::saveFile(void)
{
	std::string newfile;
	const char * tmp;

	newfile = _filename + ".replace";
	_outfile.open(newfile.c_str());
	if (_outfile.is_open())
	{
		tmp = _text.c_str();
		_outfile.write(tmp, _text.size());
		_outfile.close();
		return (true);
	}
	else
	{
		std::cout << "Failed to open the file: " << newfile << std::endl;
		return (false);
	}
}

