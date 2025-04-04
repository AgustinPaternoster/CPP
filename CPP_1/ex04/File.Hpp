#include <string>>
#include <fstream>

class File
{
	public:
		File(std::ifstream& infile, std::ofstream& outfile, std::string fname);
		~File(void);	
	
		void openFile();

		void saveFile();

		void replace(std::string s1, std::string s2);
	private:
		std::ifstream&	_infile;
		std::ofstream&  _outfile;
		std::string 	_text;
		std::string 	_filename;
};