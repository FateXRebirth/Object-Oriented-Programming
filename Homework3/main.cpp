#include "cppunitlite\TestHarness.h"
#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

int main()
{
    TestResult tr;
    TestRegistry::runAllTests(tr);
    return 0;
}

double length (double * const u, int d) {
    double ans;
    if (d < 2) throw "Wrong dimension";
    else {
        for(int i = 0 ; i < d ; i++) {
            ans = ans + (u[i]*u[i]);
        }
        return ans;
    }
}

double * scala(double * const u, int d, int a) {
    double * ans = new double[d];
    if (d<2) throw "Wrong dimension";
    else {
        for( int i = 0 ; i < d ; i++) {
            ans[i] = a * u[i];
        }
        return ans;
    }
}

TEST(length, OK){
    double u[] = {3,4};
    DOUBLES_EQUAL(5,sqrt(length(u,2)),0.1);
}

TEST(length, NotOK){
    double u[] = {3,4};
    try {
        double ans = length(u,1);
    }catch(const char * s) {
        CHECK(0==strcmp("Wrong dimension",s));
    }
}

TEST(scala, OK){
    double u[] = {3,4};
    double * ans = scala(u,2,5);
    DOUBLES_EQUAL(15,*ans,0.1);
    DOUBLES_EQUAL(20,*(ans+1),0.1);
}

TEST(scala, NotOK){
    double u[] = {3,4};
    try {
        double * ans = scala(u,1,5);
    }catch(const char * s){
        CHECK(0==strcmp("Wrong dimension",s));
    }
}
