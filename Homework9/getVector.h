#ifndef GETVECTOR_H_INCLUDED
#define GETVECTOR_H_INCLUDED

#include <string>
#include <sstream>

using namespace std;

int  StringToInt(string s){
    stringstream ss(s);
    int i;
    ss >> i;
    return i;
}

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

Vector getVectorFromStringForCircle(string s)
{
    //cout << s << endl;

    stringstream ss(s);
    int d = 2;
    double * const v = new double [d];
    char ch;
    ss >> ch;

    //cout << ch << endl;

    if(ch != '(') {
        cout << "pre" << endl;
        throw "Format error";
    }


    for( int i = 0; i<d ; i++) {
        ss >> v[i] >> ch;
        //cout << "in loop  " << v[i] << ch << endl;
    }

    for( int i = 0; i<d ; i++) {

        //cout << "in loop2  " << v[i] <<  endl;
    }


    if (ch != ')') {// dim under
        cout << "suff" << endl;
        throw "Dimension error!";
    }

    if (!ss.good()) {// dim over
        cout << "end" << endl;
        throw "Dimension error!";
    }

    Vector dv(d,v);
    delete [] v;
    return dv;
}

Vector * getVectorFromStringForConvexPolygon(int n, string s){

    //(0,0)/(3,0)/(3,4)}
    string temp;
    //cout << s << endl;

    Vector * vs = new Vector[n];
    stringstream ss(s);

    int dim = 2;
    double * v = new double[dim];
    char ch;

    ss >> ch;

    //cout << ch << endl;

    if(ch != '(') {
        cout << "pre" << endl;
        throw "Format error";
    }


    for( int i = 0; i<n ; i++) {
        for ( int j = 0; j < dim ; j++){
            ss >> v[j] >> ch;
            //cout << "in Loop " << v[j] << ch << endl;
        }
        if (ss.peek() == '/')
            ss.ignore();
        ss >> ch;

        //cout << ch << endl;

        Vector vc(dim,v);
        vs[i] = vc;
    }

    if (!ss.good()) {// dim over
        cout << "end" << endl;
        throw "Dimension error!";
    }

    return vs;
}


#endif // GETVECTOR_H_INCLUDED
