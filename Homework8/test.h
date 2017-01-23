#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

bool compare(int i , int j) { return i > j;};
void square (int & x) {x = x*x;};
template<typename T> void minusOne ( T & x) { x = x - 1;};

template <class T>
bool isPositive (T t) {return t >=0;}

template <class IT, class T, class Cond>
std::vector<T> find_all (IT begin, IT end, T, Cond cond)
{
    std::vector<T> v;
    for (IT i=begin; i != end; ++i)
        if (cond(*i))
            v.push_back(*i);
    return v;
}

TEST(p1, hw8)
{
    int test[10] = {-3,9,3,0,5,-7,3,6,-6,1};
    std::vector<int> v(test, test+10);
    std::vector<int>::iterator it;
    it = std::find(v.begin(), v.end(), -7);
    LONGS_EQUAL(-7, *it);
    it = std::find(v.begin(), v.end(), 8);
    LONGS_EQUAL(*v.end(), *it);
}

TEST(p2, hw8)
{
    int test[10] = {-3,9,3,0,5,-7,3,6,-6,1};
    std::list<int> l(test, test+10);
    std::list<int>::iterator it;
    it = std::find(l.begin(), l.end(), -7);
    LONGS_EQUAL(-7, *it);
    it = std::find(l.begin(), l.end(), 8);
    LONGS_EQUAL(*l.end(), *it);
}

TEST(p3, hw8)
{
    int test[10] = {-3,9,3,0,5,-7,3,6,-6,1};
    std::sort(test, test+10);

    LONGS_EQUAL(-7, test[0]);
    LONGS_EQUAL(-6, test[1]);
    LONGS_EQUAL(-3, test[2]);
    LONGS_EQUAL(0, test[3]);
    LONGS_EQUAL(1, test[4]);
    LONGS_EQUAL(3, test[5]);
    LONGS_EQUAL(3, test[6]);
    LONGS_EQUAL(5, test[7]);
    LONGS_EQUAL(6, test[8]);
    LONGS_EQUAL(9, test[9]);
}

TEST(p4, hw8)
{
    int test[10] = {-3,9,3,0,5,-7,3,6,-6,1};
    std::vector<int> v(test, test+10);
    std::vector<int>::iterator it;
    std::sort(v.begin(), v.end());

    LONGS_EQUAL(-7, v[0]);
    LONGS_EQUAL(-6, v[1]);
    LONGS_EQUAL(-3, v[2]);
    LONGS_EQUAL(0, v[3]);
    LONGS_EQUAL(1, v[4]);
    LONGS_EQUAL(3, v[5]);
    LONGS_EQUAL(3, v[6]);
    LONGS_EQUAL(5, v[7]);
    LONGS_EQUAL(6, v[8]);
    LONGS_EQUAL(9, v[9]);
}

TEST(p5, hw8)
{
    int test[10] = {-3,9,3,0,5,-7,3,6,-6,1};
    std::vector<int> v(test, test+10);
    std::vector<int>::iterator it;
    std::sort(v.begin(), v.end(), compare);

    LONGS_EQUAL(9, v[0]);
    LONGS_EQUAL(6, v[1]);
    LONGS_EQUAL(5, v[2]);
    LONGS_EQUAL(3, v[3]);
    LONGS_EQUAL(3, v[4]);
    LONGS_EQUAL(1, v[5]);
    LONGS_EQUAL(0, v[6]);
    LONGS_EQUAL(-3, v[7]);
    LONGS_EQUAL(-6, v[8]);
    LONGS_EQUAL(-7, v[9]);
}

TEST(p6, hw8)
{
    int test[10] = {-3,9,3,0,5,-7,3,6,-6,1};
    std::for_each(test, test+10, square);

    LONGS_EQUAL(9, test[0]);
    LONGS_EQUAL(81, test[1]);
    LONGS_EQUAL(9, test[2]);
    LONGS_EQUAL(0, test[3]);
    LONGS_EQUAL(25, test[4]);
    LONGS_EQUAL(49, test[5]);
    LONGS_EQUAL(9, test[6]);
    LONGS_EQUAL(36, test[7]);
    LONGS_EQUAL(36, test[8]);
    LONGS_EQUAL(1, test[9]);
}

TEST(p7, hw8)
{
    int test[10] = {-3,9,3,0,5,-7,3,6,-6,1};
    std::vector<int> v(test , test+10);
    for_each(v.begin(), v.end(), square);

    LONGS_EQUAL(9, v[0]);
    LONGS_EQUAL(81, v[1]);
    LONGS_EQUAL(9, v[2]);
    LONGS_EQUAL(0, v[3]);
    LONGS_EQUAL(25, v[4]);
    LONGS_EQUAL(49, v[5]);
    LONGS_EQUAL(9, v[6]);
    LONGS_EQUAL(36, v[7]);
    LONGS_EQUAL(36, v[8]);
    LONGS_EQUAL(1, v[9]);
}


TEST(p8, hw8)
{
    //Part a
    int test[10] = {-3,9,3,0,5,-7,3,6,-6,1};
    std::vector<int> v(test , test+10);
    for_each(v.begin(), v.end(), minusOne<int>);

    LONGS_EQUAL(-4, v[0]);
    LONGS_EQUAL(8, v[1]);
    LONGS_EQUAL(2, v[2]);
    LONGS_EQUAL(-1, v[3]);
    LONGS_EQUAL(4, v[4]);
    LONGS_EQUAL(-8, v[5]);
    LONGS_EQUAL(2, v[6]);
    LONGS_EQUAL(5, v[7]);
    LONGS_EQUAL(-7, v[8]);
    LONGS_EQUAL(0, v[9]);

    //Part b
    double test2[10] = {-3.0,9.0,3.0,0.0,5.0,-7.0,3.0,6.0,-6.0,1.0};
    std::list<double> l(test2 , test2+10);
    for_each(l.begin(), l.end(), minusOne<double>);
    std::list<double>::iterator it;

    int i = 0;
    for( it = l.begin(); it != l.end(); ++it) {
        //std::cout << *it << std::endl;
        LONGS_EQUAL(test2[i]-1.0,*it);
        i++;
    }
}

TEST(p9, hw8)
{

    //Part a
    int a[10] = {-3,9,3,0,5,-7,3,6,-6,1};
    std::vector<int> v = find_all(a, a+10, 0, isPositive<int>);

    LONGS_EQUAL(9,v[0]);
    LONGS_EQUAL(3,v[1]);
    LONGS_EQUAL(0,v[2]);
    LONGS_EQUAL(5,v[3]);
    LONGS_EQUAL(3,v[4]);
    LONGS_EQUAL(6,v[5]);
    LONGS_EQUAL(1,v[6]);

    //Part b
    double b[10] = {-3.0,9.0,3.0,0.0,5.0,-7.0,3.0,6.0,-6.0,1.0};
    std::list<double> lb(b, b+10);
    std::vector<double> v2 = find_all(lb.begin(), lb.end(), 0.0, isPositive<double>);

    DOUBLES_EQUAL(9,v2[0],0.001);
    DOUBLES_EQUAL(3,v2[1],0.001);
    DOUBLES_EQUAL(0,v2[2],0.001);
    DOUBLES_EQUAL(5,v2[3],0.001);
    DOUBLES_EQUAL(3,v2[4],0.001);
    DOUBLES_EQUAL(6,v2[5],0.001);
    DOUBLES_EQUAL(1,v2[6],0.001);
}


#endif // TEST_H_INCLUDED
