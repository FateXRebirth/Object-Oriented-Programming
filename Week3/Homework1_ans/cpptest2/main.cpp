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
    LONGS_EQUAL(12, add(10,2));
}
TEST(TestAdd_Negative, Add)
{
    LONGS_EQUAL(-12, add(-10,-2));
}
TEST(TestSubtracte_Positive, Operation)
{
    LONGS_EQUAL(8, sub(18, 10));
}
TEST(TestSubtract_Negative, Operation)
{
    LONGS_EQUAL(-8, sub(-18, -10));
}
TEST(TestMultiply_Positive, Operation)
{
    LONGS_EQUAL(20, mul(4, 5));
}
TEST(TestMultiply_Negative, Operation)
{
    LONGS_EQUAL(20, mul(-4, -5));
}
TEST(TestMaxnum, Number)
{
    LONGS_EQUAL(10, maxnum(10, 1));
}
TEST(TestMinimum, Number)
{
    LONGS_EQUAL(2, minimum(3, 2));
}
