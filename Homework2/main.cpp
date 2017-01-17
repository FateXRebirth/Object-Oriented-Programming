#include "cppunitlite\TestHarness.h"
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    TestResult tr;
    TestRegistry::runAllTests(tr);
    return 0;
}

double * const sum (double * const v, double * const u, int d1, int d2) {
    double * sum = new double[d1];
    if( d1 != d2 ) throw "Different dimension";
    else {
        for ( int i=0 ; i < d1 ; i++) {
            sum[i] = v[i]+u[i];
        }
        return sum;
    }
}

double const Sum3 (double * const u, double * const v, double w, int d1, int d2) {
    // To calculate w x ( u + v ) = w x u + w x v //
    double sum;
    if ( d1 != d2 ) throw "Different dimension";
    else {
        for ( int i = 0 ; i < d2 ; i++ ) {
            double temp = w*u[i]+w*v[i];
            sum = sum + temp;
        }
        return sum;
    }
}

TEST(sum, OK) {
    double u[] = {1,2};
    double v[] = {2,3};
    double * ans = sum(u,v,2,2);
    DOUBLES_EQUAL(3,*ans,0.1);
    DOUBLES_EQUAL(5,*(ans+1),0.1);
}

TEST(sum, NotOK) {
    double u[] = {1,2,3};
    double v[] = {3,4};
    try {
        double * ans = sum(u,v,3,2);
    }catch(const char * s){
        CHECK(0==strcmp("Different dimension",s));
    }
}

TEST(Sum3, OK){
    double u[] = {1,2};
    double v[] = {1,3};
    double w = 4;
    double ans = Sum3(u,v,w,2,2);
    DOUBLES_EQUAL(28,ans,0.1);
}

TEST(Sum3, NotOK) {
    double u[] = {1,2,3};
    double v[] = {3,4};
    double w = 5;
    try {
        double ans = Sum3(u,v,w,3,2);
    }catch(const char * s){
        CHECK(0==strcmp("Different dimension",s));
    }
}



