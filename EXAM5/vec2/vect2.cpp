#include "vect2.hpp"

Vect2::Vect2(int x , int y)
{
    vector[0] = x;
    vector[1] = y;
}

Vect2::Vect2(void)
{
    vector[0] = 0;
    vector[1] = 0;
}

Vect2::Vect2(const Vect2& other)
{
    if(this != &other)
    {
        this->vector[0] = other.vector[0];
        this->vector[1] = other.vector[1];
    }
}

Vect2::~Vect2(void){}

Vect2& Vect2::operator=(const Vect2& other)
{
    if(this != &other)
    {
        this->vector[0] = other.vector[0];
        this->vector[1] = other.vector[1];        
    }
    return(*this);
}

Vect2 Vect2::operator+(int nb)
{
    Vect2 tmp;
    tmp.vector[0] = this->vector[0] + nb;
    tmp.vector[1] = this->vector[1] + nb;
    return(tmp);
}

Vect2 Vect2::operator+(const Vect2& other)
{
    Vect2 tmp;
    tmp.vector[0] = this->vector[0] + other.vector[0];
    tmp.vector[1] = this->vector[1] + other.vector[1];
    return (tmp);
}

Vect2 Vect2::operator-(int nb)
{
    Vect2 tmp;
    tmp.vector[0] = this->vector[0] - nb;
    tmp.vector[1] = this->vector[1] - nb;
    return(tmp);
}

Vect2 Vect2::operator-(const Vect2& other)
{
    Vect2 tmp;
    tmp.vector[0] = this->vector[0] - other.vector[0];
    tmp.vector[1] = this->vector[1] - other.vector[1];
    return (tmp);
}

Vect2 Vect2::operator*(int nb)
{
    Vect2 tmp;
    tmp.vector[0] = this->vector[0] * nb;
    tmp.vector[1] = this->vector[1] * nb;
    return(tmp);
}

Vect2 Vect2::operator*(const Vect2& other)
{
    Vect2 tmp;
    tmp.vector[0] = this->vector[0] * other.vector[0];
    tmp.vector[1] = this->vector[1] * other.vector[1];
    return (tmp);
}

Vect2& Vect2::operator+=(const Vect2& other)
{
    this->vector[0] += other.vector[0];
    this->vector[1] += other.vector[1];
    return(*this);
}

Vect2& Vect2::operator+=(int nb)
{
    this->vector[0] += nb;
    this->vector[1] += nb;
    return(*this);
}

Vect2& Vect2::operator-=(const Vect2& other)
{
    this->vector[0] -= other.vector[0];
    this->vector[1] -= other.vector[1];
    return(*this);
}

Vect2& Vect2::operator-=(int nb)
{
    this->vector[0] -= nb;
    this->vector[1] -= nb;
    return(*this);
}

Vect2& Vect2::operator*=(const Vect2& other)
{
    this->vector[0] *= other.vector[0];
    this->vector[1] *= other.vector[1];
    return(*this);
}

Vect2& Vect2::operator*=(int nb)
{
    this->vector[0] *= nb;
    this->vector[1] *= nb;
    return(*this);
}

Vect2& Vect2::operator++(void)
{
    *this += 1;
    return(*this);
}

Vect2 Vect2::operator++(int)
{
    Vect2 tmp(*this);
    *this += 1;
    return(tmp);
}

Vect2& Vect2::operator--(void)
{
    *this -= 1;
    return(*this);
}

Vect2 Vect2::operator--(int)
{
    Vect2 tmp(*this);
    *this -= 1;
    return(tmp);
}

int Vect2::getV1(void)const
{
    return(vector[0]);
}

int Vect2::getV2(void)const
{
    return(vector[1]);
}

bool Vect2::operator==(const Vect2& other)
{
    if(this->vector[0] == other.vector[0] && this->vector[1] == other.vector[1])
        return (true);
    return(false);
}

bool Vect2::operator!=(const Vect2& other)
{
    if(this->vector[0] == other.vector[0] && this->vector[1] == other.vector[1])
        return (false);
    return(true);
}

int Vect2::operator[](int idx)
{
    return(this->vector[idx]);
}

std::ostream& operator<<(std::ostream& os, const Vect2& other)
{
    os << "{" << other.getV1() << ", " << other.getV2() << "}";
    return(os);
}