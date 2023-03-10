#include "Point.h"

using namespace std;

Point::Point(double nx, double ny, double nz){
    x = nx;
    y = ny;
    z = nz;

}

Point::Point(int nx, int ny, int nz){
    x = nx;
    y = ny;
    z = nz;

}

double Point::getX() const{
    return x;
}

double Point::getY() const{
    return y;
}

double Point::getZ() const{
    return z;
}

void Point::setX(double a){
    x = a;
}

void Point::setY(double a){
    y = a;
}

void Point::setZ(double a){
    z = a;
}

void Point::setXYZ(double nx, double ny, double nz){
    x = nx;
    y = ny;
    z = nz;
}

double Point::length(){
    return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
}

void Point::operator =(const Point &p){
    x = p.getX();
    y = p.getY();
    z = p.getZ();
}

Point operator +(const Point &p1, const Point &p2){
    double nx = p2.x + p1.x;
    double ny = p2.y + p1.y;
    double nz = p2.z + p1.z;

    Point np(nx, ny, nz);
    return np;
}

Point operator -(const Point &p1, const Point &p2){
    double nx = p1.x - p2.x;
    double ny = p1.y - p2.y;
    double nz = p1.z - p2.z;

    Point np(nx, ny, nz);
    return np;
}

ostream &operator << (ostream &out, const Point &p){

    out << "(" << p.x << ", " << p.y << ", " << p.z << ")";

    return out;
}

Point operator *(const int &a, const Point &p){
    double nx = a * p.x;
    double ny = a * p.y;
    double nz = a * p.z;

    Point np(nx, ny, nz);
    return np;
}

Point operator *(const Point &p, const int &a){
    double nx = a * p.x;
    double ny = a * p.y;
    double nz = a * p.z;

    Point np(nx, ny, nz);
    return np;
}

double operator *(const Point &p1, const Point &p2){
    double nx = p1.x * p2.x;
    double ny = p1.y * p2.y;
    double nz = p1.z * p2.z;
    return nx + ny + nz;
}

Point operator /(const Point &p, const int &a){
    double nx = p.x / a;
    double ny = p.y / a;
    double nz = p.z / a;

    Point np(nx, ny, nz);
    return np;
}

bool operator ==(const Point &p1, const Point &p2){
    return p1.x == p1.x && p1.y == p2.y && p1.z == p2.z;
}
