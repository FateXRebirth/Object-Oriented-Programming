#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED
#include "..\cppunitlite\TestHarness.h"
#include <algorithm>
#include "..\Vector.h"
#include "..\ConvexPolygon\ConvexPolygon.h"
#include <sstream>

#include <list>

using namespace std;


bool smallInFront(int a, int b) {
    return a < b;
}

bool bigPerimeterInFront(ConvexPolygon const & a, ConvexPolygon const & b) {
    return a.perimeter() > b.perimeter();
}

template<class T>
bool bigInFront(T a, T b) {
    return a > b;
}

bool bigInFrontVector(Vector const & a, Vector const & b) {
    return a.length() > b.length();
}

class closestToGivenVector {
public:
    closestToGivenVector(Vector const & v):r(v){}
    bool operator () (Vector const & a, Vector const & b) {
        return (a-r).length() > (b-r).length();
    }
private:
    Vector r;
};
TEST (sort, int) {
    int a[] = {3,2,5,1};
    sort(a,a+4);
    LONGS_EQUAL(1,a[0]);
    LONGS_EQUAL(2,a[1]);
    LONGS_EQUAL(3,a[2]);
    LONGS_EQUAL(5,a[3]);
}
TEST (sort, double) {
    double a[] = {3.1,2.1,5.1,1.1};
    sort(a,a+4);
    DOUBLES_EQUAL(1.1,a[0],0.0001);
    DOUBLES_EQUAL(2.1,a[1],0.0001);
    DOUBLES_EQUAL(3.1,a[2],0.0001);
    DOUBLES_EQUAL(5.1,a[3],0.0001);
}

TEST (sort, smallInFront) {
    int a[] = {3,2,5,1};
    sort(a,a+4, smallInFront);
    LONGS_EQUAL(1,a[0]);
    LONGS_EQUAL(2,a[1]);
    LONGS_EQUAL(3,a[2]);
    LONGS_EQUAL(5,a[3]);
}

TEST (sort, bigInFront) {
    int a[] = {3,2,5,1};
    sort(a,a+4, bigInFront<int>);
    LONGS_EQUAL(5,a[0]);
    LONGS_EQUAL(3,a[1]);
    LONGS_EQUAL(2,a[2]);
    LONGS_EQUAL(1,a[3]);
}

TEST (sort, bigInFrontDouble) {
    double a[] = {3.1,2.1,5.1,1.1};
    sort(a,a+4, bigInFront<double>);
    LONGS_EQUAL(5.1,a[0]);
    LONGS_EQUAL(3.1,a[1]);
    LONGS_EQUAL(2.1,a[2]);
    LONGS_EQUAL(1.1,a[3]);
}

TEST(sort, bigInFrontVector) {
    double a[]={2,3};
    double b[]={2,4};
    double c[]={0,0};
    Vector va(2,a);
    Vector vb(2,b);
    Vector vc(2,c);
    Vector vs[] = {va,vb,vc};
    sort(vs,vs+3,bigInFront<Vector>);
    CHECK(vb==vs[0]);
    CHECK(va==vs[1]);
    CHECK(vc==vs[2]);
}

TEST(sort, closestToGivenVector) {
    double a[]={2,3};
    double b[]={2,4};
    double c[]={0,0};
    double d[]={1,1};
    Vector va(2,a);
    Vector vb(2,b);
    Vector vc(2,c);
    Vector vd(2,d);
    Vector vs[] = {va,vb,vc};

//    closestToGivenVector refvec(vd);
//    sort(vs,vs+3,refvec);
    sort(vs,vs+3,closestToGivenVector(vd));
    CHECK(vb==vs[0]);
    CHECK(va==vs[1]);
    CHECK(vc==vs[2]);
}

TEST(string, add) {
    stringstream ss;
    int n=1;
    ss << n;
    CHECK(string("1")==ss.str());

}

TEST (vector, first) {
int a[]={0,2,4,6,8,10,12,14,16,18};
  int size = sizeof(a)/sizeof(int);
  vector<int>va(a, a+size);
  vector<int>::iterator key;

  for (int i=0; i<size; ++i)
    if ((key=find(va.begin(),va.end(),i)) != va.end())
      cout << "va[" <<key-va.begin()<<"] = " << *key << "\n";
}
#endif // TESTS_H_INCLUDED
