#ifndef PRODUCTDOT_H_INCLUDED
#define PRODUCTDOT_H_INCLUDED

#include <string>
#include "Vector.h"
#include <algorithm>

using namespace std;

double product_dot(Vector & a,Vector & b)
{
    double ans = 0;
    int i;
    if(a.dimension() == b.dimension())
        for(i=1;i<=a.dimension();i++)
            ans += a.component(i)*b.component(i);
    else
        throw string("exception");
    return ans;
}

int * const
minus_vector(int a[], int b[] , int da ,int db)
{
    int i;
    int * const ans = new int[da];
    if(da == db)
        for(i=0;i<da;i++)
            ans[i] = a[i] -b[i];
    else
        throw string("subtract_exception");
    return ans ;
}

Vector centroid(int n, Vector vs[]) {
    // check dimension;
    double a[vs[0].dimension()];
    for (int i=0; i<vs[0].dimension(); ++i)
        a[i] = 0;
    for (int i=1; i<=vs[0].dimension(); ++i) {
        for (int j=0; j<n; ++j)
            a[i-1] += vs[j].component(i);
    }
    for (int i=0; i<vs[0].dimension();++i)
        a[i] /= n;
    return Vector(vs[0].dimension(),a);
}

void order(int n, Vector vs[], Vector const &v) {
    Vector c(Vector::centroid(n, vs));
    std::sort(vs,vs+n,smallAngleInFront(c,v));
}


#endif // PRODUCTDOT_H_INCLUDED
