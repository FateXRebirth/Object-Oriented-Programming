#ifndef CONVEXPOLYGON_H_INCLUDED
#define CONVEXPOLYGON_H_INCLUDED
#include "Vector.h"
#include "triangle_area.h"
#include "centroid.h"
#include "ProductDot.h"
#include <string>
#include <algorithm>

class ConvexPolygon {
public:
    static ConvexPolygon create(int n, Vector vs[], Vector const & refV) {
        order(n,vs,refV);
        return ConvexPolygon(n, vs);
    }
public:
    ConvexPolygon(int a, Vector vs[])
    :n(a),v(new Vector[a]){
        for (int i=0; i<n; ++i)
            v[i] = vs[i];
    }
    int n_vertices() const {return n;}
    Vector & vertex(int i) const {
        if (i<1 || i> n)
            throw std::string("illegal vertex index");
        return v[i-1];}

    double perimeter () const {
        double p=0.0;
        for (int i=2; i<=n; ++i)
            p += (vertex(i)-vertex(i-1)).length();
        p += (vertex(1)-vertex(n)).length();
        return p;
    }
    double area() const{
        double a=0.0;
        for(int i=2; i<n; ++i)
            a+= triangle_area(vertex(1),vertex(i),vertex(i+1));
        return a;
    }
private:
    int n;
    Vector * v;
};
#endif // CONVEXPOLYGON_H_INCLUDED
