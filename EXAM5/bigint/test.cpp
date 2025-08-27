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
    std::string nb1 = "21";
    std::string nb2 = "100000";
    std::string result;
    int rest = 0;
    int char1;
    int char2;
    char c;
    
    while (!nb1.empty() || !nb2.empty())
    {
        if(!nb1.empty())
        {
            char1 = charToint(nb1.back());
            nb1.pop_back();
        }
        if(!nb2.empty())
        {
            char2 = charToint(nb2.back());
            nb2.pop_back();
        }
        c = (((char1 + char2) % 10) + rest) + 48;
        rest = (char1 + char2) / 10 ;
        result = c + result;
        char1 = 0;
        char2 = 0;
    }
    if (rest != 0)
        result = static_cast<char>(rest + 48) + result;
    std::cout << result <<std::endl;
}