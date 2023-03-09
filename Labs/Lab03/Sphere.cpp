//Author: Charles Reigle
//Creation Date: 2/16/2023
//Last Update: 2/16/2023
//Description: Implementation of the Sphere class
//Notes: 

#include "Sphere.h"

using namespace std;


// Takes in an x, y, z, and radius coordinate and constructs it
// Default values set in prototype in the header.
Sphere::Sphere(double ix, double iy, double iz, double ir){
    x = ix;
    y = iy;
    z = iz;
    
    if(ir < 0) rad = 0;
    else rad = ir;
    
}

// Deconstructor does nothing
Sphere::~Sphere(){
}

// Updates the center coordinates to the input x y and z
void Sphere::setCenter(double ix, double iy, double iz){
    x = ix;
    y = iy;
    z = iz;
}

// Updates the radius to the input value
void Sphere::setRadius(double ir){
    if(ir < 0) rad = 0;
    else rad = ir;
}

// Returns a double of the x coordinate of the center
double Sphere::getX() const{
    return x;
}   

// Returns a double of the y coordinate of the center
double Sphere::getY() const{
    return y;
}

// Returns a double of the z coordinate of the center
double Sphere::getZ() const{
    return z;
}

// Returns a double of the radius
double Sphere::getRadius() const{
    return rad;
}

// Returns true or false depending on whether or not the input sphere and the current sphere are colliding 
// with one another
bool Sphere::collide(Sphere s2){
   
    double dist = distance(s2.getX(), s2.getY(), s2.getZ());
    double sum = rad + s2.getRadius();
    
    return dist < sum;
}

// Prints out the info of the sphere into the console
void Sphere::printSphereInfo(){
    cout << "Center: (" << x << ", " << y << ", " << z << ")   Radius: " << rad << endl;
}

// Returns a double of the distance between the main sphere and the input  y and z coordinates
double Sphere::distance(double x2, double y2,  double z2){
    
    double powX = pow((x2 - x), 2);
    double powY = pow((y2 -y), 2);
    double powZ = pow((z2 - z), 2);
    
    return sqrt(powX + powY + powZ);
}

// Returns true or false after analyzing whether or not the curent sphere and the input sphere have the
// same data values
bool Sphere::isEqual(Sphere s2){
// This entire function can probably be done in a better way but I don't have time to research into it.
    return (x == s2.getX()) && (y == s2.getY()) && (z == s2.getZ()) && (rad == s2.getRadius()); 
}
