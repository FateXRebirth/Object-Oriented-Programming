#ifndef GETVECTOR_H_INCLUDED
#define GETVECTOR_H_INCLUDED

#include <string>
#include <sstream>

using namespace std;

int * const extractVector(string s, int * dim)
{
    stringstream ss(s);

    int d;
    int i;
    ss >> d;
    if(d < 1)
        throw ("dimension_error");

    int * const v = new int [d];
    *dim = d;
    for(i = 0; i < d; i++)
        ss >> v[i];
    return v;
}

Vector extractVector(string s)
{
    stringstream ss(s);

    int d;
    int i;
    ss >> d;
    if(d < 1)
        throw ("dimension_error");

    double * const v = new double [d];
    for(i = 0; i < d; i++)
        ss >> v[i];
    Vector dv(d,v);
    delete [] v;
    return dv;
}

char extractContinue(string s)
{
    stringstream ss(s);
    char c;
    ss >> c;
    return c;
}
#endif // GETVECTOR_H_INCLUDED
