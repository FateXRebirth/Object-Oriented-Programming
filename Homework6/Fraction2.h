#ifndef FRACTION2_H_INCLUDED
#define FRACTION2_H_INCLUDED

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int
gcd ( int a, int b )
{
    int c;
    while ( a != 0 )
    {
            c = a;
            a = b%a;
            b = c;
    }
    return b;
}
class Fraction
{
public:
    Fraction()
    {
        nume = 0;
        demo = 1;
        si = 1;
    }
    Fraction(int integer)
    {
        nume = abs(integer);
        demo = 1;
        if(integer < 0)
            si = 0 ;
        else if(integer > 0)
            si = 1;
    }
    Fraction(int n , int d)
    {
        if(d==0)
            throw string( "Denominator cannot be zero!");

        nume = abs(n) ;
        demo = abs(d);
        if( (n<0&&d<0) || (n>0&&d>0) )
            si=1;
        else
            si=0;
    }
    Fraction operator + (Fraction & f)
    {

        Fraction ans(*this);
        ans.nume = ans.nume*f.demo +ans.demo*f.nume;
        ans.demo = ans.demo * f.demo;
        if(gcd(ans.nume,ans.demo)!=1)
        {
            int a = gcd(ans.nume,ans.demo);
            ans.nume/=a;
            ans.demo/=a;
        }
        return ans;
    }
    string str()
    {
        stringstream ss;
        string ans ;
        if(si == 0)
            ss << "-" ;
        if(nume == 0)
        {
            ss << 0;
            ss >> ans;
            return ans;
        }

        ss << nume;
        ss << "/";
        ss << demo;

        ss >> ans ;
        return ans ;
    }
    char sign()
    {
        if(si==0)
            return '-';
        else
            return '+';
    }
    double value()
    {
        if(si==0)
            return -((double)nume / demo);
        else
            return ((double)nume / demo);
    }

    int numerator() {return nume;}
    int denominator() {return demo;}

private:
    int nume;
    int demo;
    bool si;
};
bool
FractionLT(Fraction a ,Fraction b)
{
    return(a.value()< b.value());
}
bool
FractionGT(Fraction a ,Fraction b)
{
    return(a.value()> b.value());
}

#endif // FRACTION2_H_INCLUDED
