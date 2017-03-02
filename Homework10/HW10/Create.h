#ifndef CREATE_H_INCLUDED
#define CREATE_H_INCLUDED
#include <cmath>
#include "..\matrix\Matrix.h"

double PI = 3.14159265359;

Matrix
RotateMatrix(double angle);

ConvexPolygon createRegularPolygon(int n) {
    Vector *vs = new Vector[n];
    Matrix m = RotateMatrix((2*PI) / n );
    double v[] = {1, 0};
    Vector vn(2, v);
    vs[0] = vn;
    for(int i = 1; i < n; i++){
        vn = apply(m, vn);
        vs[i] = vn;
    }
    return ConvexPolygon(n, vs);
}

Matrix RotateMatrix(double a){
    double v[] = {cos(a), -1.0*sin(a), sin(a), cos(a)};
    return Matrix(2, 2, v);
}

ConvexPolygon translate(Vector const & v, ConvexPolygon const & p) {
    Vector vs[p.n_vertices()];
    for(int i = 0; i < p.n_vertices(); i++){
        vs[i] = p.vertex(i+1) + v;
    }
    return ConvexPolygon(p.n_vertices(),vs);
}
#endif // CREATE_H_INCLUDED
