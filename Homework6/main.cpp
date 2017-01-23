#include "cppunitlite\TestHarness.h"
#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;

//#include "Fraction.h"
#include "Fraction2.h"

int main()
{
    TestResult tr;
    TestRegistry::runAllTests(tr);
    return 0;
}

TEST (create, Fraction)
{
    Fraction f;
    LONGS_EQUAL(0,f.numerator());
    LONGS_EQUAL(1,f.denominator());
    LONGS_EQUAL('+',f.sign());
}

TEST (create_2, Fraction)
{
    Fraction f(3);
    LONGS_EQUAL(3,f.numerator());
    LONGS_EQUAL(1,f.denominator());
    LONGS_EQUAL('+',f.sign());

    Fraction g(-7);
    LONGS_EQUAL(7,g.numerator());
    LONGS_EQUAL(1,g.denominator());
    LONGS_EQUAL('-',g.sign());
}

TEST (create_3, Fraction)
{
    Fraction f(1,3);
    LONGS_EQUAL(1,f.numerator());
    LONGS_EQUAL(3,f.denominator());
    LONGS_EQUAL('+',f.sign());

    Fraction g(-1,3);
    LONGS_EQUAL(1,g.numerator());
    LONGS_EQUAL(3,g.denominator());
    LONGS_EQUAL('-',g.sign());

    Fraction h(-1,-3);
    LONGS_EQUAL(1,h.numerator());
    LONGS_EQUAL(3,h.denominator());
    LONGS_EQUAL('+',h.sign());
    try {
        Fraction h(-1,0);
        FAIL("Should not each here!");
    }
    catch (std::string s) {
        CHECK(std::string("Denominator cannot be zero!")==s);
    }
}

TEST (str, Fraction)
{
    Fraction g(-1,3);
    CHECK(std::string("-1/3")==g.str());
    Fraction h(-1,-3);
    CHECK(std::string("1/3")==h.str());
}

TEST (op_add, Fraction)
{
    Fraction g(2,4);
    Fraction h(1,3);
    Fraction f = g + h;
    LONGS_EQUAL(5,f.numerator());
    LONGS_EQUAL(6,f.denominator());
    LONGS_EQUAL('+',f.sign());
}

TEST (op_add2, Fraction)
{
    Fraction g(-2,4);
    Fraction h(1,3);
    Fraction f = g + h;
    LONGS_EQUAL(5,f.numerator());
    LONGS_EQUAL(6,f.denominator());
    LONGS_EQUAL('-',f.sign());
}

TEST (op_add3, Fraction)
{
    Fraction g(2,-4);
    Fraction h(1,3);
    Fraction f = g + h;
    LONGS_EQUAL(5,f.numerator());
    LONGS_EQUAL(6,f.denominator());
    LONGS_EQUAL('-',f.sign());
}

TEST (op_add4, Fraction)
{
    Fraction g(-2,-4);
    Fraction h(1,3);
    Fraction f = g + h;
    LONGS_EQUAL(5,f.numerator());
    LONGS_EQUAL(6,f.denominator());
    LONGS_EQUAL('+',f.sign());
}
/*
TEST(op_sub, Fraction)
{
    Fraction g(2,4);
    Fraction h(1,3);
    Fraction f = g - h;
    LONGS_EQUAL(1,f.numerator());
    LONGS_EQUAL(6,f.denominator());
    LONGS_EQUAL('+',f.sign());
}

TEST(op_sub2, Fraction)
{
    Fraction g(-2,4);
    Fraction h(1,3);
    Fraction f = g - h;
    LONGS_EQUAL(5,f.numerator());
    LONGS_EQUAL(6,f.denominator());
    LONGS_EQUAL('-',f.sign());
}

TEST(op_gt, Fraction){
    Fraction g(2,4);
    Fraction h(1,3);
    Fraction f(5,6);
    CHECK_EQUAL(true,g>h);
    CHECK_EQUAL(true,f>h);
    CHECK_EQUAL(false,g>f);
}

TEST(op_lt, Fraction){
    Fraction g(2,4);
    Fraction h(1,3);
    Fraction f(5,6);
    CHECK_EQUAL(false,g<h);
    CHECK_EQUAL(false,f<h);
}

TEST(op_eq, Fraction)
{
    Fraction g(2,3);
    Fraction f = g;
    LONGS_EQUAL(2,f.numerator());
    LONGS_EQUAL(3,f.denominator());
}

TEST(Refer, Fraction){
    Fraction g(3,4);
    Fraction f(g);
    LONGS_EQUAL(3,f.numerator());
    LONGS_EQUAL(4,f.denominator());
}

TEST (mcu, Fraction){
    Fraction T;
    LONGS_EQUAL(12,T.mcu(3,4));
    LONGS_EQUAL(15,T.mcu(3,5));
    LONGS_EQUAL(21,T.mcu(3,7));
}
*/
TEST (gcd, Fraction)
{
    LONGS_EQUAL(1,gcd(3,7));
    LONGS_EQUAL(1,gcd(-3,7));
    LONGS_EQUAL(3,gcd(3,9));
    LONGS_EQUAL(1,gcd(1,9));
    LONGS_EQUAL(9,gcd(9,9));
}


TEST (sortingLT, Fraction)
{
    Fraction a;
    Fraction b(-1);
    Fraction c(-2,-3);
    Fraction d(2,4);
    Fraction e(1,3);

    Fraction fs[5]={a,b,c,d,e};

    std::sort(fs, fs+5, FractionLT);

    CHECK(std::string("-1/1")==fs[0].str());
    CHECK(std::string("0")==fs[1].str());
    CHECK(std::string("1/3")==fs[2].str());
    CHECK(std::string("2/4")==fs[3].str());
    CHECK(std::string("2/3")==fs[4].str());
}

TEST (sortingGT, Fraction)
{
    Fraction a;
    Fraction b(-1);
    Fraction c(-2,-3);
    Fraction d(2,4);
    Fraction e(1,3);

    Fraction fs[5]={a,b,c,d,e};
    std::sort(fs, fs+5, FractionGT);

    CHECK(std::string("-1/1")==fs[4].str());
    CHECK(std::string("0")==fs[3].str());
    CHECK(std::string("1/3")==fs[2].str());
    CHECK(std::string("2/4")==fs[1].str());
    CHECK(std::string("2/3")==fs[0].str());
}
