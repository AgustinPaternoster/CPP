#include <iostream>
#include <sstream>

int charToint(char c)
{
    return(c - 48);
}

// int main(void)
// {
    
    
//     std::string nb = "12345";
    
//     for (int)
//     {
//         char c = ((i % 10) + 48);
//         nb = c + nb;
//     }
//     std::cout << nb << std::endl;
// }

int main(void)
{ 
    std::string nb1 = "00032000";
    std::string nb2 = "100000";
    
    for (int i = 0; nb1.front() == 48; i++)
    {
        nb1.erase(nb1.begin());
    }
    std::cout << nb1 <<std::endl;
}