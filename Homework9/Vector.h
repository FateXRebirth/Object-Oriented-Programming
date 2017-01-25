#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <string>
#include <math.h>
#include <iostream>
#include <sstream>

using namespace std;
const double pi = 3.14159265;
class Vector;

class Vector {
public:
    static Vector centroid(int n, Vector vs[]) {
        Vector v(vs[0]);
        for (int i=1; i<n; ++i) {
            v = v + vs[i];
        }
        return v/n;
    }
    static bool zout (Vector const & va, Vector const & vb) {
        // check dimension == 2
        return va.component(1)*vb.component(2) >= va.component(2)*vb.component(1);
    }
public:
    Vector():dim(0),comp(0){}
    Vector (int d, double * com) {
        dim = d;
        comp = new double[d];
        for (int i=0; i< d; ++i)
            comp[i] = com[i];
    }
    Vector (const Vector & v) {
        dim = v.dim;
        comp = new double[dim];
        for (int i=0; i< dim; ++i)
            comp[i] = v.comp[i];
    }

    Vector & operator = (const Vector & v) {
        if (comp)
            delete [] comp;
        dim = v.dim;
        comp = new double [dim];
        for (int i=0; i <dim; ++i)
            comp[i] = v.comp[i];
        return *this;
    }
    bool operator == (const Vector & v){
        bool result = true;
        if(dim != v.dimension())
            result = false;
        else
            for(int i=0; i<dim; i++)
                if(comp[i] != v.comp[i]) {
                    result = false;
                    break;
                }
        return result;
    }

    Vector operator - (Vector const & v) const {
        if (dim != v.dim)
            throw string("illegal dimension");
        Vector r(*this);
        for (int i=0; i<dim; ++i)
            r.comp[i] -= v.comp[i];
        return r;
    }

    Vector operator + (Vector const & v) const {
        if (dim != v.dim)
            throw string("illegal dimension");
        Vector r(*this);
        for (int i=0; i<dim; ++i)
            r.comp[i] += v.comp[i];
        return r;
    }

    Vector operator / (double d) const {
        Vector r(*this);
        for (int i=0; i<dim; ++i)
            r.comp[i] /= d;
        return r;
    }

    double length() const {
        double sumsq = 0.0;    //CHECK(Vector::zout(va,vb));

        for (int i=0; i<dim; ++i)
            sumsq += double(comp[i])*double(comp[i]);
        return sqrt(sumsq);
    }

    bool operator > (Vector const & v) {
        return length() > v.length();
    }
    int dimension() const {return dim;}
    double component(int i) const {
        return comp[i-1];
    }
    ~Vector() {
        if (comp) delete [] comp;
    }

    double operator * (Vector const & v) const {
        if (v.dim != dim)
            throw string("Unequal dimension");
        double dotProduct =0;
        for (int i = 0; i< dim; ++i) {
            dotProduct += comp[i]*v.comp[i];
        }
        return dotProduct;
    }
    string str() const {
        stringstream ss;
        ss << "(";
        for (int i=1; i<dim; ++i)
            ss << component(i) <<",";
        ss << component(dim) <<")";
        return ss.str();
    }
    /*
    string description() {
        stringstream ss;
        ss << "(";
        for ( int i=0 ; i < dim; i++)
            ss << component(i+1) << ",";
        ss << ")";
        return ss.str();
    }
    */
private:
    int dim;
    double * comp;

public:
};

class smallAngleInFront {
public:
    smallAngleInFront(Vector const & cent, Vector const & refVec)
     :c(cent), r(refVec){ }
     bool operator () (Vector const & a, Vector const & b) {
        Vector vr = r-c;
        Vector va = a-c;
        Vector vb = b-c;
        double thetaa = acos(vr*va/(vr.length()*va.length()));
        double thetab = acos(vr*vb/(vr.length()*vb.length()));
        if (!Vector::zout(vr,va))
            thetaa = 2*pi - thetaa;
        if (!Vector::zout(vr,vb))
            thetab = 2*pi - thetab;
        return thetaa < thetab;
     }
private:
    Vector c;
    Vector r;
};

ostream & operator << (ostream & os, Vector const & v) {
    os << v.str();
    return os;
}


#endif // VECTOR_H_INCLUDED
