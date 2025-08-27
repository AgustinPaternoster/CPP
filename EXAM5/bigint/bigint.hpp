#ifndef __BIGINT_H__
#define __BIGINT_H__
#include <string>
#include <iostream>
#include <sstream>

class Bigint
{
    public:
        Bigint(void);
        Bigint(std::string nb);
        Bigint(int nb);
        Bigint(const Bigint& other);
        ~Bigint(void);

        std::string getNumber(void) const;
        Bigint& operator=(const Bigint& other);
        Bigint operator+(const Bigint& other);
        // Bigint operator++(int);
        // Bigint& operator++(void);
        Bigint& operator+=(const Bigint& other);

        Bigint& operator>>(int nb);
        // Bigint& operator>>(const);

        bool operator<(const Bigint& other);
        bool operator>(const Bigint& other);
        bool operator>=(const Bigint& other);
        bool operator<=(const Bigint& other);
        bool operator!=(const Bigint& other);
        bool operator==(const Bigint& other);






        private:
            std::string _number;
};

std::ostream& operator<<(std::ostream & o, Bigint const & rsc);
#endif