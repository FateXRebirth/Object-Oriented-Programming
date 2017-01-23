#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

#include <string>

class Shape {
public:
    virtual std::string description() const =0;
};

/*
std::string printShapeInfo(Shape const & s){
    return s.description();
}
*/

template <class T>
std::string printShapeInfo(T const & s){
    return s.description();
}


#endif // SHAPE_H_INCLUDED
