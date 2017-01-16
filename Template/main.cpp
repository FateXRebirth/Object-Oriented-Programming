#include "cppunitlite\TestHarness.h"
#include <iostream>
#include <cmath>
using namespace std;

int add(int input_a, int input_b)
{
    return input_a + input_b;
}
int sub(int input_a, int input_b)
{
    return input_a - input_b;
}
int mul(int input_a, int input_b)
{
    return input_a * input_b;
}
int maxnum(int input_a, int input_b)
{
    if(input_a >= input_b)
        return input_a;

    return input_b;
}
int minimum(int input_a, int input_b)
{
    if(input_a <= input_b)
        return input_a;

    return input_b;
}

int main()
{
    TestResult tr;
    TestRegistry::runAllTests(tr);
    return 0;
}
TEST(TestAdd_Positive, Add)
{
    //TODO
    int ans = add(5,3);
    LONGS_EQUAL(8,ans);

}
TEST(TestAdd_Negative, Add)
{
    //TODO
    int ans = add(-3,-5);
    LONGS_EQUAL(-8,ans);
}
TEST(TestSubtract_Positive, Subtract)
{
    //TODO
    int ans = sub(8,5);
    LONGS_EQUAL(3,ans);
}
TEST(TestSubtract_Negative, Subtract)
{
    //TODO
    int ans = sub(-8,-5);
    LONGS_EQUAL(-3,ans);
}
TEST(TestMultiply_Positive, Multiply)
{
    //TODO
    int ans = mul(5,3);
    LONGS_EQUAL(15,ans);
}
TEST(TestMultiply_Negative, Multiply)
{
    //TODO
    int ans = mul(-5,-3);
    LONGS_EQUAL(15,ans);
}
TEST(TestMaxnum, Maxnum)
{
    //TODO
    int ans = maxnum(10,5);
    LONGS_EQUAL(10,ans);
}
TEST(TestMinimum, Minimum)
{
    //TODO
    int ans = minimum(10,5);
    LONGS_EQUAL(5,ans);
}
