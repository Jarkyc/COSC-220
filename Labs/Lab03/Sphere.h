//Author: Charles Reigle
//Creation Date: 2/16/2023
//Last Update: 2/16/2023
//Description: Layout of the Sphere class
//Notes: 


#ifndef SPHERE_H
#define SPHERE_H

#include <iostream>
#include <cmath>

class Sphere{
  
public:
    Sphere(double ix = 0, double iy = 0, double iz = 0, double ir = 1);
    ~Sphere();
    
    void setCenter(double ix = 0, double iy = 0, double iz = 0);
    void setRadius(double ir = 1);
    double getRadius() const;
    double getX() const;
    double getY() const;
    double getZ() const ;
    bool collide(Sphere s);
    void printSphereInfo();
    bool isEqual(Sphere s);
private:
    double x;
    double y; 
    double z;
    double rad;
    
    double distance(double, double, double);
};


#endif
