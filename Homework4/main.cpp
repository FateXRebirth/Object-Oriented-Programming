#include "cppunitlite\TestHarness.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int main()
{
    TestResult tr;
    TestRegistry::runAllTests(tr);
    return 0;
}

double * const getVector(string line, int * dim) {
    stringstream ss(line);

    int d;
    int i;
    char c;
    ss >> d >> c;
    if(d < 1)
        throw "dimension error";

    double * const v = new double [d];
    *dim = d;
    for(i = 0; i < d-1 ; i++) {
        ss >> v[i] >> c ;
        if (c != ',') {
            if(!ss.eof())
                throw "dimension error";
            else
                throw "format error";
        }
    }
    ss >> v[d-1] >> c;
    if( !ss.good() || c != ')') {
        if(!ss.eof())
            throw "dimension error";
        else
            throw "format error";
    }
    return v;
}

TEST(getVector, OK){
    string s("3 (1,2,3)");
    int d;
    double * v = getVector(s,&d);
    DOUBLES_EQUAL(3,d,0.001);
    DOUBLES_EQUAL(1,v[0],0.001);
    DOUBLES_EQUAL(2,v[1],0.001);
    DOUBLES_EQUAL(3,v[2],0.001);
}

TEST(getVector, OK2){
    string s("1 (0)");
    int d;
    double * v = getVector(s,&d);
    DOUBLES_EQUAL(1,d,0.001);
    DOUBLES_EQUAL(0,v[0],0.001);
}

TEST(getVector, NotOK){
    string s("1 (1,2)");
    int d;
    try {
        double * v = getVector(s,&d);
    }catch(const char * s) {
        cout << "Wrong Here" <<endl;
    }
}

TEST(getVector, NotOK2) {
    string s("3 (1,2)");
    int d;
    try {
        double * v = getVector(s,&d);
    }catch(const char * s) {
        cout << "Wrong Here" <<endl;
    }
}

TEST(getVector, NotOK3) {
    string s("2 (1,2");
    int d;
    try {
        double * v = getVector(s,&d);
    }catch(const char * s) {
        cout << "Wrong Here" <<endl;
    }
}

TEST(getVector, NotOK4) {
    string s("-1 (1,2)");
    int d;
    try {
        double * v = getVector(s,&d);
    }catch(const char * s) {
        cout << "Wrong Here" <<endl;
    }
}
