#include "bigint.hpp"

Bigint::Bigint(void):_number("0"){};
Bigint::Bigint(std::string nb):_number(nb)
{
    if (_number.size() > 1)
    {
        while( _number.front() == 48)
            _number.erase(_number.begin());
    }
};

Bigint::Bigint(int nb)
{
    std::ostringstream ss;
    ss << nb;
    _number = ss.str();
} 

Bigint::Bigint(const Bigint& other)
{
    *this = other;
}

Bigint::~Bigint(void){};

Bigint& Bigint::operator=(const Bigint& other)
{
    if(this != &other)
    {
        _number = other._number;
    }

    return (*this);
}

Bigint Bigint::operator+(const Bigint& other)
{
    std::string nb1= other.getNumber();
    std::string nb2 = this->getNumber();
    std::string result;
    char c;
    int char1 = 0;
    int char2 = 0;
    int rest = 0;
    while(!nb1.empty() || !nb2.empty())
    {
        if(!nb1.empty())
        {
            char1 = nb1.back() - 48;
            nb1.pop_back();
        }
        if(!nb2.empty())
        {
            char2 = nb2.back() - 48;
            nb2.pop_back();
        }
        c = (((char1 + char2)%10) + rest) + 48;
        result = c + result;
        rest = (char1 + char2) / 10;
        char1 = 0;
        char2 = 0;
    }
    if (rest < 0)
        result = (char)(rest + 48) + result;
    return (Bigint(result));
}

Bigint& Bigint::operator+=(const Bigint& other)
{
    *this = *this + other;
    return(*this);
}



Bigint& Bigint::operator++(void)
{
    Bigint tmp(1);
    *this += tmp;
    return(*this);
}

Bigint Bigint::operator++(int)
{
    Bigint tmp(*this);
    Bigint one(1);
    *this += one;
    return(tmp);
}

bool Bigint::operator<(const Bigint& other)
{
    if (this->_number.size() < other._number.size())
        return (true);    
    if (this->_number.size() > other._number.size())
        return (false);
    if(this->_number.compare(other._number) < 0)
        return (true);
    return(false);
}

bool Bigint::operator>(const Bigint& other)
{
    if (this->_number.size() > other._number.size())
        return (true);    
    if (this->_number.size() < other._number.size())
        return (false);
    if(this->_number.compare(other._number) > 0)
        return (true);
    return (false);
}

bool Bigint::operator<=(const Bigint& other)
{
    if (this->_number.size() < other._number.size())
        return (true);    
    if (this->_number.size() > other._number.size())
        return (false);
    if(this->_number.compare(other._number) <= 0)
        return (true);
    return(false);
}

bool Bigint::operator>=(const Bigint& other)
{
    if (this->_number.size() > other._number.size())
        return (true);    
    if (this->_number.size() < other._number.size())
        return (false);
    if(this->_number.compare(other._number) >= 0)
        return (true);
    return (false);
}

bool Bigint::operator!=(const Bigint& other)
{
    if (this->_number.size() != other._number.size())
        return (true);
    if(this->_number.compare(other._number) != 0)
        return (true);
    return (false);
}

bool Bigint::operator==(const Bigint& other)
{
    if (this->_number.size() != other._number.size())
        return (false);
    if(this->_number.compare(other._number) == 0)
        return (true);
    return (false);
}

Bigint Bigint::operator>>(int nb)
{
    Bigint tmp(*this);
    
    for(int i = 0; i < nb && !tmp._number.empty(); i++)
        tmp._number.pop_back();
    if(tmp._number.empty())
        tmp._number = "0";
    return(tmp);
}

Bigint Bigint::operator>>(const Bigint& other)
{
    std::string nTmp = other._number; 
    Bigint tmp(*this);
    int mult = 1;
    while (!nTmp.empty())
    {
        for (int i = 0; i < (nTmp.back() - 48) * mult; i++)
        {
            tmp._number.pop_back(); 
            if(tmp._number.empty())
            {
                tmp._number = "0";
                return(tmp);
            }
        }
        mult *= 10;
        nTmp.pop_back();
    }
    return (tmp);
}


Bigint Bigint::operator<<(int nb)
{
    Bigint tmp(*this);
    
    if (tmp._number.size() < 2 && tmp._number[0] == 48)
        return(tmp);
    for(int i = 0; i < nb && !tmp._number.empty(); i++)
        tmp._number = tmp._number + "0";
    return(tmp);
}

Bigint Bigint::operator<<(const Bigint& other)
{
    std::string nTmp = other._number; 
    Bigint tmp(*this);
    if (tmp._number.size() < 2 && tmp._number[0] == 48)
        return (tmp);
    int mult = 1;
    while (!nTmp.empty())
    {
        for (int i = 0; i < (nTmp.back() - 48) * mult; i++)
            tmp._number = tmp._number + "0"; 
        mult *= 10;
        nTmp.pop_back();
    }
    return (tmp);
}

Bigint& Bigint::operator>>=(int nb)
{
    if(this->_number.size() < 2 && this->_number[0] == 48)
        return(*this);
    for (int i = 0; i < nb && !this->_number.empty(); i++)
        this->_number.pop_back();
    if(this->_number.empty())
        this->_number = "0";
    return (*this);
}

Bigint& Bigint::operator>>=(const Bigint& other)
{
    if(this->_number.size() < 2 && this->_number[0] == 48)
        return(*this);
    Bigint tmp(other);
    int mult = 1;
    while (!tmp._number.empty())
    {
        for (int i = 0; i < (tmp._number.back() - 48) * mult; i++)
        {
            this->_number.pop_back();
            if(this->_number.empty())
            {
                this->_number = "0";
                return(*this);
            }
        }
        mult *= 10;
        tmp._number.pop_back();
    }
    return (*this);
}

Bigint& Bigint::operator<<=(int nb)
{
    if(this->_number.size() < 2 && this->_number[0] == 48)
        return(*this);
    for (int i = 0; i < nb ; i++)
        this->_number.push_back('0');
    return (*this);
}

Bigint& Bigint::operator<<=(const Bigint& other)
{
    if(this->_number.size() < 2 && this->_number[0] == 48)
        return(*this);
    Bigint tmp(other);
    int mult = 1;
    while (!tmp._number.empty())
    {
        for (int i = 0; i < (tmp._number.back() - 48) * mult; i++)
            this->_number.push_back('0');
        mult *= 10;
        tmp._number.pop_back();
    }
    return (*this);
}


std::string Bigint::getNumber(void) const
{
    return (_number);
}


std::ostream& operator<<(std::ostream &o , const Bigint& rsc)
{
    o << rsc.getNumber();
    return (o);
}