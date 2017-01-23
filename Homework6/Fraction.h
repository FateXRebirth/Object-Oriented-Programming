#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int gcd(int a, int b);

class Fraction {

public:
    Fraction();
    Fraction(int numerator);
    Fraction(int numerator, int denominator);
    Fraction(const Fraction & g);
    ~Fraction();
    Fraction operator + (Fraction & g);
    Fraction operator - (Fraction & g);
    Fraction operator = (Fraction g);
    bool operator > (Fraction & g);
    bool operator < (Fraction & g);
    int numerator();
    int denominator();
    char sign();
    string str();
    void determine();
    int mcu(int a, int b);
    double value();
private:
    int _numerator;
    int _denominator;
    char _sign;
};

Fraction::Fraction(){
    _numerator = 0;
    _denominator = 1;
    determine();
}

Fraction::Fraction(int numerator){
    _numerator = numerator;
    _denominator = 1;
    determine();
}

Fraction::Fraction(int numerator, int denominator){
    if ( denominator == 0) throw string("Denominator cannot be zero!");
    else {
        _numerator = numerator;
        _denominator = denominator;
        determine();
    }
}

Fraction::Fraction(const Fraction & g){
    this->_denominator = g._denominator;
    this->_numerator = g._numerator;
    this->_sign = g._sign;
}

Fraction::~Fraction(){}


void Fraction::determine(){
    if ( _numerator < 0 && _denominator < 0 ) {
        _sign = '+';
    }else if( _numerator < 0 || _denominator < 0 ){
        _sign = '-';
    }else {
        _sign = '+';
    }
    if (_denominator < 0) _denominator *= -1;
    if (_numerator < 0) _numerator *= -1;
}
char Fraction::sign(){
    return _sign;
}

int Fraction::numerator(){
    return _numerator;
}

int Fraction::denominator(){
    return _denominator;
}

Fraction Fraction::operator+(Fraction & g){
    char sign1 = this->sign();
    char sign2 = g.sign();
    int nume1 = this->numerator();
    int nume2 = g.numerator();
    int deno1 = this->denominator();
    int deno2 = g.denominator();
    int both = mcu(deno1,deno2);
    int times1 = both/deno1;
    int times2 = both/deno2;

    int f_nume;
    int f_deno;
    int both_gcd;

    if(sign1 == sign2){
        if(sign1 == '+'){
            f_nume = times1*nume1 + times2*nume2;
            f_deno = both;
            both_gcd = gcd(abs(f_nume),abs(f_deno));
            f_nume = f_nume/both_gcd;
            f_deno = f_deno/both_gcd;
        }
        else{
            f_nume = times1*nume1 + times2*nume2;
            f_deno = both;
            both_gcd = gcd(abs(f_nume),abs(f_deno));
            f_nume = f_nume/both_gcd;
            f_deno = f_deno/both_gcd;
            f_nume *= -1;
        }
    }else{
        if(sign1 == '+'){
            f_nume = times1*nume1 - times2*nume2;
            f_deno = both;
            both_gcd = gcd(abs(f_nume),abs(f_deno));
            f_nume = f_nume/both_gcd;
            f_deno = f_deno/both_gcd;
        }else{
            f_nume = times2*nume2 - times1*nume1;
            f_deno = both;
            both_gcd = gcd(abs(f_nume),abs(f_deno));
            f_nume = f_nume/both_gcd;
            f_deno = f_deno/both_gcd;
        }
    }
    Fraction f(f_nume,f_deno);
    return f;

}

Fraction Fraction::operator-(Fraction & g){
    char sign1 = this->sign();
    char sign2 = g.sign();
    int nume1 = this->numerator();
    int nume2 = g.numerator();
    int deno1 = this->denominator();
    int deno2 = g.denominator();

    int both = mcu(deno1,deno2);
    int times1 = both/deno1;
    int times2 = both/deno2;

    int f_nume;
    int f_deno;
    int both_gcd;

    if(sign1 == sign2){
        if(sign1 == '+'){
            f_nume = times1*nume1 - times2*nume2;
            f_deno = both;
            both_gcd = gcd(abs(f_nume),abs(f_deno));
            f_nume = f_nume/both_gcd;
            f_deno = f_deno/both_gcd;
        }
        else{
            f_nume = times1*nume1 - times2*nume2;
            f_deno = both;
            both_gcd = gcd(abs(f_nume),abs(f_deno));
            f_nume = f_nume/both_gcd;
            f_deno = f_deno/both_gcd;
            f_nume *= -1;
        }
    }else{
        if(sign1 == '+'){
            f_nume = times1*nume1 + times2*nume2;
            f_deno = both;
            both_gcd = gcd(abs(f_nume),abs(f_deno));
            f_nume = f_nume/both_gcd;
            f_deno = f_deno/both_gcd;
        }else{
            f_nume = times2*nume2 + times1*nume1;
            f_deno = both;
            both_gcd = gcd(abs(f_nume),abs(f_deno));
            f_nume = f_nume/both_gcd;
            f_deno = f_deno/both_gcd;
            f_nume *= -1;
        }
    }
    Fraction f(f_nume,f_deno);
    return f;
}

Fraction Fraction::operator=(Fraction g){
    Fraction f;
    f._numerator = g.numerator();
    f._denominator = g.denominator();
    f._sign = g.sign();
    return f;
}

bool Fraction::operator>(Fraction & g){
    Fraction num1(*this);
    Fraction num2(g);
    Fraction fin;
    char sign1 = num1.sign();
    char sign2 = num2.sign();
    if(sign1 == sign2){
        fin = num1-num2;
        if(fin.sign()=='+')return true;
        else return false;
    }else{
        if(sign1 == '+') return true;
        else return false;
        if(sign2 == '+') return false;
        else return true;
    }
}

bool Fraction::operator<(Fraction & g){
    Fraction num1(*this);
    Fraction num2(g);
    Fraction fin;
    char sign1 = num1.sign();
    char sign2 = num2.sign();
    if(sign1 == sign2){
        fin = num1-num2;
        if(fin.sign()=='+')return false;
        else return true;
    }else{
        if(sign1 == '+') return false;
        else return true;
        if(sign2 == '+') return true;
        else return false;
    }
}

int Fraction::mcu(int a, int b) {
    int x = a;
    while(x%b!=0){
        x = x + a;
    }
    return x;
}

string IntToString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}

string CharToString (char a)
{
    stringstream ss;
    string s;
    ss << a;
    ss >> s;
    return s;
}

int gcd ( int a, int b )
{
  if ( a==0 ) return b;
  return gcd ( b%a, a );
}


string Fraction::str(){
    string a = IntToString(_numerator);
    string b = IntToString(_denominator);
    string sign;
    if ( _sign == '-' ) sign = CharToString(_sign);
    if (_numerator == 0 && _denominator == 1) return "0";
    return sign+a+"/"+b;
}

bool FractionGT (Fraction i, Fraction j)
{
    return (i.value() > j.value());
}

bool FractionLT (Fraction i, Fraction j)
{
    return (i.value() > j.value());
}

class test{
public:
    bool operator () (Fraction i , Fraction j ){
        return (i>j);
    }
}comp;

struct test2{
    bool operator () (Fraction i, Fraction j){
        return (i>j);
    }
}comp2;

double Fraction::value(){
    if(_sign == '-'){
        return -((double)_numerator/_denominator);
    }else{
        return ((double)_numerator/_denominator);
    }
}
#endif // FRACTION_H_INCLUDED
