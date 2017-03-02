#ifndef UTHW10_H_INCLUDED
#define UTHW10_H_INCLUDED
#include "..\cppunitlite\TestHarness.h"
#include "..\Vector.h"
#include "..\ConvexPolygon\ConvexPolygon.h"
#include "Create.h"
#include <fstream>

using namespace std;

TEST(createRegularPolygon, OK1) {
    ConvexPolygon cp = createRegularPolygon(3);

    vector<ConvexPolygon> cps;
    cps.push_back(cp);
    cout << toSVG(cps) << endl;
    ofstream ofs("t1.svg");
    ofs <<toSVG(cps);
    ofs.close();

    CHECK(3 == cp.numofsides());
    DOUBLES_EQUAL(sqrt(3), cp.side(), 0.00001);
    DOUBLES_EQUAL(3*sqrt(3), cp.perimeter(), 0.00001);
    DOUBLES_EQUAL(3*sqrt(3)/4, cp.area(), 0.00001);
}

TEST(translate, OK2) {
    ConvexPolygon cp = createRegularPolygon(3);
    double a[] = {3,3};
    Vector va(2,a);
    ConvexPolygon cpt = translate(va,cp);

    vector<ConvexPolygon> cps;
    cps.push_back(cpt);
    cout << toSVG(cps) << endl;
    ofstream ofs("t2.svg");
    ofs <<toSVG(cps);
    ofs.close();

    double one[] = {4,3};
    double two[] = {2.5,(sqrt(3)/2)+3};
    double three[] = {2.5,-1*(sqrt(3)/2)+3};
    Vector v1(2,one);
    CHECK(v1 == cpt.vertex(1));
    DOUBLES_EQUAL(two[0], cpt.vertex(2).component(1), 0.00001);
    DOUBLES_EQUAL(two[1], cpt.vertex(2).component(2), 0.00001);
    DOUBLES_EQUAL(three[0], cpt.vertex(3).component(1), 0.00001);
    DOUBLES_EQUAL(three[1], cpt.vertex(3).component(2), 0.00001);

}

TEST(ConvexPolygon, OK3){
    int start = 3;
    int R = 5;
    int C = 5;
    double mb = 4;
    double m[2] = {0, 0};
    vector<ConvexPolygon> cpa;
    for(int i = 0; i < C; i++){
        for(int j = 0; j < R; j++){
            int S = start + i*C + j;
            ConvexPolygon cp = createRegularPolygon(S);
            m[0] = (j+1) * mb;
            m[1] = (i+1) * mb;
            Vector v(2, m);
            cp = translate(v, cp);
            cpa.push_back(cp);
        }
    }
    ofstream ofs("t3.svg");
    ofs << toSVG(cpa);
    ofs.close();
}
#endif // UTHW10_H_INCLUDED
