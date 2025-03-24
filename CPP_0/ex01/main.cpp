#include "phonebook.hpp"

int main(void)
{
    std::string command;
    
    while (1)
    {
        std::cin >> command;
        if (command.compare("EXIT") == 0)
            break;
        std::cout << command << std::endl;
    }
    return (0);
}