#ifndef _VECT2_HPP__
#define _VECT2_HPP__

#include <iostream>

class Vect2
{
    public:
        Vect2(int x , int y);
        Vect2(void);
        Vect2(const Vect2& other);
        ~Vect2(void);

        Vect2& operator=(const Vect2& other);
        int getV1(void)const;
        int getV2(void)const;

        Vect2 operator+(const Vect2& other);
        Vect2 operator+(int nb);
        Vect2 operator-(const Vect2& other);
        Vect2 operator-(int nb);
        Vect2 operator*(const Vect2& other);
        Vect2 operator*(int nb);

        Vect2& operator+=(const Vect2& ohter);
        Vect2& operator+=(int nb);
        Vect2& operator-=(const Vect2& ohter);
        Vect2& operator-=(int nb);
        Vect2& operator*=(const Vect2& ohter);
        Vect2& operator*=(int nb);

        Vect2& operator++(void);
        Vect2 operator++(int);
         Vect2& operator--(void);
        Vect2 operator--(int);

        bool operator==(const Vect2& other);
        bool operator!=(const Vect2& other);

        int operator[](int nb);


    private:
        int vector[2];
        int a;
};

std::ostream& operator<<(std::ostream& os , const Vect2& other);
#endif