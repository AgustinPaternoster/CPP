#include <iostream>
#include <string>

int main ()
{
  std::string name;

  while (1)
  {
	std::cout << "Please, enter your full name: ";
	std::getline (std::cin,name);
	if (name.empty() == 0)
	{
		std::cout << "nombre incorrecto" << std::endl;
	}
	std::cout << "Hello, " << name << "!\n";
	break;
  }
  

  return 0;
}