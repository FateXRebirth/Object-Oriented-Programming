#ifndef CONVEXPOLYGON_H_INCLUDED
#define CONVEXPOLYGON_H_INCLUDED
#include "..\Vector.h"
#include "..\triangle_area.h"
#include "..\cent.h"
#include <string>
#include <algorithm>
#include "Shape.h"

class ConvexPolygon: public Shape {
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
    string description() const {
        stringstream ss;
        ss<<"{"<<"convex polygon, "<<n;
        ss<<", [";
        for(int i=0;i<n-1;i++)
            ss<<v[i].description()<<", ";
        ss<<v[n-1].description()<<"]}";
        //ss<<area()<<", "<<perimeter()<<"}";
        return ss.str();
    }

bool operator == (ConvexPolygon const & a){
    if(n!=a.n)
        return false;
    for(int i=0;i<n;i++)
        if(!(v[i]==a.v[i]))
            return false;
    return true;

}
private:
    int n;
    Vector * v;
};

ConvexPolygon createConvexPolygon(int n,Vector vs[], Vector const & v)
{
    std::sort(vs,vs+n,smallAngleInFront(centroid(n,vs),v));
    return ConvexPolygon(n,vs);
}

bool smallPerimeterInFront(ConvexPolygon const & a,ConvexPolygon const & b){
    return a.perimeter()<b.perimeter();
}

#endif // CONVEXPOLYGON_H_INCLUDED
