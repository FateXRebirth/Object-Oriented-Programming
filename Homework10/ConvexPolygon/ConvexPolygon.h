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
    ConvexPolygon(ConvexPolygon const & cp)
    :n(cp.n),v(new Vector[cp.n]){
        for (int i=0; i<n; ++i)
            v[i] = cp.v[i];
    }
    int n_vertices() const {return n;}
    Vector & vertex(int i) const {
        if (i<1 || i> n)
            throw std::string("illegal vertex index");
        return v[i-1];
    }

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

    int numofsides() const {
        int a = n;
        return a;
    }

    double side() const {
        return (vertex(2)-vertex(1)).length();
    }

    string description() const {
        stringstream ss;
        ss<<"{"<<"convex polygon, "<<n;
        ss<<", [";
        for(int i=0;i<n-1;i++)
            ss<<v[i].description()<<", ";
        ss<<v[n-1].description()<<"]}";
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
    string toSVG() const
    {
        stringstream ss;
        ss << "<polygon points=\"";
        for (int i=0; i < n-1; ++i)
            ss << v[i].toSVG()<< " ";
        ss << v[n-1].toSVG() <<"\"\n";
        ss << "         style=\"stroke:orangered; stroke-width: 0.1; fill:navy;\"/>";
        return ss.str();
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

string toSVG(vector<ConvexPolygon> & vs)
{
    stringstream ss;
    ss << "<svg xmlns=\"http://www.w3.org/2000/svg\"\n";
    ss << "     width=\"1000\" height=\"1000\" viewBox=\"0 0 25 25\">\n";
    for (int i=0;  i<(int)vs.size(); ++i)
        ss << vs[i].toSVG() << "\n";
    ss << "</svg>";
    return ss.str();
}

#endif // CONVEXPOLYGON_H_INCLUDED
