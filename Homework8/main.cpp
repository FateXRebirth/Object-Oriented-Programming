#include "cppunitlite\TestHarness.h"
#include <iostream>
#include <cmath>
#include "test.h"
using namespace std;

int main()
{
    TestResult tr;
    TestRegistry::runAllTests(tr);
    return 0;
}
