#include "cppunitlite\TestHarness.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include "ConvexPolygon.h"
#include "Vector.h"
#include "ProductDot.h"
#include "getVector.h"
#include "Circle.h"

using namespace std;

int main()
{
    TestResult tr;
    TestRegistry::runAllTests(tr);
    return 0;
}

const double epislon = 0.0001;

TEST(ConvexPolygon, Constructor){
    double u[]={0,0}, v[]={3,0}, w[]={3,4};
    Vector a(2,u), b(2,v), c(2,w);
    Vector vertices[]={a,b,c};
    ConvexPolygon cp(3,vertices);
    LONGS_EQUAL(3,cp.n_vertices());
    /*
    LONGS_EQUAL(0,cp.vertex(1).component(1));
    LONGS_EQUAL(0,cp.vertex(1).component(2));
    */
    CHECK(a == cp.vertex(1));
}

TEST(ConvexPolygon, outofboundlow){
    double u[]={0,0}, v[]={3,0}, w[]={3,4};
    Vector a(2,u), b(2,v), c(2,w);
    Vector vertices[]={a,b,c};
    ConvexPolygon cp(3,vertices);

    try {
        cp.vertex(0);
        FAIL("exception not throw");
    } catch(string s) {
        CHECK (string("illegal vertex index") == s);
    }
}

TEST(ConvexPolygon, outofboundhigh){
    double u[]={0,0}, v[]={3,0}, w[]={3,4};
    Vector a(2,u), b(2,v), c(2,w);
    Vector vertices[]={a,b,c};
    ConvexPolygon cp(3,vertices);

    try {
        cp.vertex(4);
        FAIL("exception not throw");
    } catch(string s) {
        CHECK (string("illegal vertex index") == s);
    }
}

TEST(ConvexPolygon, perimeter){
    double u[]={0,0}, v[]={3,0}, w[]={3,4};
    Vector a(2,u), b(2,v), c(2,w);
    Vector vertices[]={a,b,c};
    ConvexPolygon cp(3,vertices);

    DOUBLES_EQUAL(12.0,cp.perimeter(),0.000);
}

TEST (ConvexPolygon, area) {
    double u[]={0,0}, v[]={3,0}, w[]={3,4};
    Vector a(2,u), b(2,v), c(2,w);
    Vector vertices[]={a,b,c};
    ConvexPolygon cp(3,vertices);

    DOUBLES_EQUAL(6.0,cp.area(),0.0001);
}

TEST(ConvexPolygon, area1){
    double u[]={1,-1}, v[]={1,1}, w[]={-1,1},x[]={-1,-1};
    Vector a(2,u), b(2,v), c(2,w), d(2,x);
    Vector vertices[]={a,b,c,d};
    ConvexPolygon cp(4,vertices);

    DOUBLES_EQUAL(4.0,cp.area(),0.0001);
}

TEST (ConvexPolygon, create) {

   double a[]={1,1}, b[]={-1,1}, c[] ={-1,-1},d[]={1,-1};
   Vector va(2,a),vb(2,b),vc(2,c),vd(2,d);
   Vector vertices[] = {va,vb,vc,vd};
   ConvexPolygon cp(ConvexPolygon::create(4,vertices, vd));
   CHECK(vd==cp.vertex(1));
   CHECK(va==cp.vertex(2));
   CHECK(vb==cp.vertex(3));
   CHECK(vc==cp.vertex(4));

   DOUBLES_EQUAL(4*2.0,cp.perimeter(),epislon);
   DOUBLES_EQUAL(2.0*2.0,cp.area(),epislon);
}

TEST (ConvexPolygon, create_hashed) {
   double a[]={1,1}, b[]={-1,1}, c[] ={-1,-1},d[]={1,-1};
   Vector va(2,a),vb(2,b),vc(2,c),vd(2,d);
   Vector vertices[] = {vc,vb,va,vd};
   ConvexPolygon cp(ConvexPolygon::create(4,vertices, vc));
   CHECK(vc==cp.vertex(1));
   CHECK(vd==cp.vertex(2));
   CHECK(va==cp.vertex(3));
   CHECK(vb==cp.vertex(4));
}

const double epsilon = 0.0001;
TEST(Vector, first) {
  double a[] = {1,2};
  Vector v(2,a);
  LONGS_EQUAL(2,v.dimension());
  DOUBLES_EQUAL(1,v.component(1), epsilon);
  DOUBLES_EQUAL(2,v.component(2), epsilon);
}

TEST(product_dot, OK_vector) {
    double a[]={2,3};
    double b[]={3,4.1};
    Vector va(2,a);
    Vector vb(2,b);
    DOUBLES_EQUAL(18.3, product_dot(va,vb),epsilon);
}

TEST(extractVector,ok){
    string s("2 1 2.1");

    Vector v(extractVector(s));

    LONGS_EQUAL(2, v.dimension());
    DOUBLES_EQUAL(1, v.component(1),epsilon);
    DOUBLES_EQUAL(2.1, v.component(2),epsilon);
}

TEST(Vector, copyAssignment) {
  double a[] = {1,2};
  Vector v(2,a);
  Vector u;
  LONGS_EQUAL(0,u.dimension());
  u = v;
  LONGS_EQUAL(2,u.dimension());
  DOUBLES_EQUAL(1,u.component(1),epsilon);
  DOUBLES_EQUAL(2,u.component(2),epsilon);
}

TEST(Vector, subtract) {
    double a[]={2,3};
    double b[]={3,4};
    Vector va(2,a);
    Vector vb(2,b);
    Vector vc = vb-va;
    LONGS_EQUAL(1, vc.component(1));
    LONGS_EQUAL(1, vc.component(2));
}

TEST (Vector, length) {
    double a[]={3,4};
    Vector va(2,a);
    DOUBLES_EQUAL(5.0, va.length(), 0.0001);
}

TEST (Vector, equality)
{
    double a[]={2, 1, 2}, b[] = {2, 1, 2};
    Vector v1(3, a), v2(3, b);
    CHECK(v1 == v2);
}

TEST(Vector, dot) {
    double a[]={2, 1, 2}, b[] = {2, 1, 2};
    Vector v1(3, a), v2(3, b);
    DOUBLES_EQUAL(9,v1*v2,epsilon);
}


TEST (centroid, double1)
{
   double a[]={1,1}, b[]={-1,1}, c[] ={-1,-1},d[]={1,-1};
   Vector va(2,a),vb(2,b),vc(2,c),vd(2,d);
   Vector vertices[] = {va,vb,vc,vd};
   Vector cent(centroid(4,vertices));
   double cv[]={0,0};
   CHECK(Vector(2,cv)==cent);
}

TEST (centroid, double2)
{
   double a[]={0,0}, b[]={3,0}, c[] ={3,4};
   Vector va(2,a),vb(2,b),vc(2,c);
   Vector vertices[] = {va,vb,vc};
   Vector cent(centroid(3,vertices));
   double cv[]={2,4.0/3};
   CHECK(Vector(2,cv)==cent);
}

TEST (Vector, centroid)
{
   double a[]={0,0}, b[]={3,0}, c[] ={3,4};
   Vector va(2,a),vb(2,b),vc(2,c);
   Vector vertices[] = {va,vb,vc};
   Vector cent(Vector::centroid(3,vertices));
   double cv[]={2,4.0/3};
   CHECK(Vector(2,cv)==cent);
}

TEST (Vector, zout) {
   double a[]={1,0}, b[]={0,1};
   Vector va(2,a),vb(2,b);
   CHECK(Vector::zout(va,vb));
}

TEST (Vector, zin) {
   double a[]={1,0}, b[]={0,1};
   Vector va(2,a),vb(2,b);
   CHECK(!Vector::zout(vb,va));
}

TEST(Vector, sort) {
   double a[]={1,1}, b[]={-1,1}, c[] ={-1,-1},d[]={1,-1};
   Vector va(2,a),vb(2,b),vc(2,c),vd(2,d);
   Vector vertices[] = {va,vb,vc,vd};
   order(4,vertices,vd);
   CHECK(vd==vertices[0]);
   CHECK(va==vertices[1]);
   CHECK(vb==vertices[2]);
   CHECK(vc==vertices[3]);
}

TEST (Vector, zout2) {
    double a[] = { 1,0}, b[]={0,1};
    Vector va(2,a), vb(2,b);
    CHECK(Vector::zout(va,vb));
    CHECK(!Vector::zout(vb,va));
    CHECK(Vector::zout(va,va));
}
TEST (centroid, exception) {
    double a[]={1,1}, b[]={-1,1}, c[] ={-1,-1, 0},d[]={1,-1};
    Vector va(2,a),vb(2,b),vc(3,c),vd(2,d);
    Vector vertices[] = {va,vb,vc,vd};
    try {
        Vector::centroid(3,vertices);
        FAIL("Not throw Exception");
    } catch(string s) {
        CHECK(s==string("illegal dimension"));
    }
}

TEST(product_dot, subtract){
     int a[]={1,2};
     int b[]={3,4};
     int c[]={2,2};
     int * const d = minus_vector(b,a,2,2);

     LONGS_EQUAL(c[0],d[0]);
     LONGS_EQUAL(c[1],d[1]);
     delete []d;
}

TEST(product_dot, subtract_exception){
     int a[]={0};
     int b[]={0,0};
     try {
         minus_vector(b,a,2,1);
         FAIL("subtract_exception not thrown");
     }
     catch (string s) {
        CHECK(s == "subtract_exception");
     }
}

TEST(ConvexPolygon, Create){
    string s("{convex polygon; 3; (0,0)/(3,0)/(3,4)}");
    ConvexPolygon cp = getConvexPolygonFromString(s);
    cout << cp.description() << endl;
}

TEST(Circle, Create){
    string s("{circle; (0,0); 1}");
    Circle c = getCircleFromString(s);
    cout << c.description() << endl;
}
