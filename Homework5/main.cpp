#include "cppunitlite\TestHarness.h"
#include <iostream>
#include <cmath>
#include "Vector.h"
using namespace std;

int main()
{
    TestResult tr;
    TestRegistry::runAllTests(tr);
    return 0;
}

double product_dot(Vector u, Vector v){
    int d1 = u.dim();
    int d2 = v.dim();
    double sum = 0;
    if ( d1 != d2) throw "Different dimension";
    else {
        for ( int i = 0 ; i < d1 ; i++){
            sum = sum + (u.component(i)*v.component(i));
        }
    }
    return sum;
}

double * product_scalar(Vector v,int a){
    int d = v.dim();
    double * ans = new double[d];
    if ( a==0 || d==0) throw "Error";
    else {
        for ( int i = 0 ; i < d ; i++){
            ans[i] = v.component(i)*a;
        }
    }
    return ans;
}

double * sum(Vector u, Vector v){
    int d1 = u.dim();
    int d2 = v.dim();
    double * sum = new double[d1];
    if ( d1 != d2 ) throw "Different dimension";
    else {
        for ( int i = 0 ; i < d1 ; i++){
            sum[i] = u.component(i)+v.component(i);
        }
    }
    return sum;
 }

 double length(Vector v){
    int d = v.dim();
    double length = 0;
    if ( d == 0) throw "Error";
    else {
        for ( int i = 0 ; i < d ; i++){
            length = length + v.component(i)*v.component(i);
        }
    }
    return length;
 }

 TEST(product_dot, OK){
    double testdata1[] = {2,3};
    double testdata2[] = {3,4};
    Vector v(testdata1,2);
    Vector u(testdata2,2);
    DOUBLES_EQUAL(18, product_dot(v,u), 0.001);
 }

 TEST(product_dot, NotOK){
     double testdata1[] = {2,3};
     double testdata3[] = {5};
     Vector v(testdata1,2);
     Vector u(testdata3,1);
     try{
        double ans = product_dot(v,u);
     }catch(const char * s){
        cout << "Wrong here1" << endl;
     }
 }

 TEST(product_scalar, OK){
     double testdata1[] = {2,3};
     Vector v(testdata1,2);
     int a = 5;
     double * ans = product_scalar(v,a);
     DOUBLES_EQUAL(10, *ans, 0.001);
     DOUBLES_EQUAL(15, *(ans+1), 0.001);
 }

 TEST(product_scalar, NotOK){
    double testdata2[] = {3,4};
    Vector v(testdata2,2);
    int a = 0;
    try {
        double * ans = product_scalar(v,a);
    }catch(const char * s){
        cout << "Wrong here2" << endl;
    }
 }

 TEST(length, OK){
     double testdata2[] = {3,4};
     Vector v(testdata2,2);
     DOUBLES_EQUAL(5,sqrt(length(v)),0.001);
 }

 TEST(length, NotOK){
    double testdata4[] = {};
    Vector v(testdata4,0);
    try{
        length(v);
    }catch(const char * s){
        cout << "Wrong here3" << endl;
    }
 }

 TEST(sum, OK){
    double testdata1[] = {2,3};
    Vector v(testdata1,2);
    Vector u(v);
    double * ans = sum(v,u);
    DOUBLES_EQUAL(4,*ans,0.001);
    DOUBLES_EQUAL(6,*(ans+1),0.001);
 }

 TEST(sum, NotOK){
    double testdata1[] = {2,3};
    double testdata3[] = {5};
    Vector v(testdata1,2);
    Vector u(testdata3,1);
    try{
        sum(v,u);
    }catch(const char * s){
        cout << "Wrong here4" << endl;
    }
 }
