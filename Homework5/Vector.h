#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

class Vector {
public:
    Vector (double a[], int d);
    Vector (Vector const & v);
    int dim() const;
    double component(int i) const;
    ~Vector();
    void show();
private:
    double * coms;
    int d;
};

Vector::Vector(double a[], int d){
    this->d = d;
    this->coms = a;
}

Vector::Vector(Vector const & v){
    this->d = v.dim();
    this->coms = v.coms;
}

int Vector::dim() const  {
    return d;
}

double Vector::component(int i) const {
    return coms[i];
}

Vector::~Vector(){
    delete coms;
}

void Vector::show(){
    for ( int i = 0 ; i < d ; i++) {
        std::cout << component(i) << std::endl;
    }
}

#endif // VECTOR_H_INCLUDED
