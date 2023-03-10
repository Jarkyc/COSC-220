#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class Point{
private:
    double x;
    double y;
    double z;
public:
    Point(double x = 0, double y = 0, double z = 0);
    Point(int x, int y, int z);
    double getX() const;
    double getY() const;
    double getZ() const;
    double length();
    void setX(double);
    void setY(double);
    void setZ(double);
    void setXYZ(double, double, double);
    void operator =(const Point&);
    friend Point operator +(const Point&, const Point&);
    friend Point operator -(const Point&, const Point&);
    friend ostream &operator << (ostream&, const Point&);
    friend Point operator * (const int&, const Point&);
    friend Point operator * (const Point&, const int&);
    friend double operator *(const Point&, const Point&);
    friend Point operator /(const Point&, const int&);
    friend bool operator ==(const Point&, const Point&);


};

#endif
