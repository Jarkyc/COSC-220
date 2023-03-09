//Author: Charles Reigle
//Creation Date: 2/16/2023
//Last Update: 2/16/2023
//Description: Main file for doing math and operations on spheres. 
//User Interface:
//                  (Number of spheres): Console input for the number of spheres to generate
//Notes: 

#include <iostream>
#include "Sphere.h"
#include <ctime>
#include <cstdlib>

using namespace std;

struct Pair{
    Sphere p1;  // Item 1 in the pair
    Sphere p2;  // Item 2 in the pair
    int index1; // Item1 index in the pair
    int index2; // Item2 index in the pair
};

double randPt();
bool hasPair(Pair*, int, Pair);

const int MAX_VAL = 10;     // Max coordinate value
const int MIN_VAL = -10;    // Min coordinate value

int main(){

    int amnt = 0;       // Amount of spheres to generate
    Sphere *spheres;    // List of all generated spheres  
    srand(time(0));
    
    cout << "Input the number of spheres: ";
    cin >> amnt;
    
    
    // Create and populate spheres
    spheres = new Sphere[amnt];
    for(int i = 0; i < amnt; i++){
        double x = randPt();
        double y = randPt();
        double z = randPt();
        
        double rnd = (double)rand() / RAND_MAX;
        double r = (rnd * .4) + .1;
        
        Sphere s(x, y, z, r);
        spheres[i] = s; 
    } 
    
    
    // Debug
    /**
    for(int i = 0; i < amnt; i++){
        cout << "---------------------" << endl;
        cout << i+1 <<": ";
        spheres[i].printSphereInfo();
    } **/
    
    // Testing the hasPair function
    Sphere s1(1, 2, 3, 1);
    Sphere s2(3, 2, 1, 1);
    
    Pair p;
    p.p1 = s1;
    p.p2 = s2;
    
    Pair *pairs = new Pair[1];
    pairs[0] = p;
    
    Pair pt;
    pt.p1 = s2;
    pt.p2 = s1;
    
    cout << endl;
    cout << hasPair(pairs, 1, pt);
    
    // Calculate all the collisions
    
        // Go through and analyze all the spheres
        // If 2 are colliding:
        //      Check to see if they are already in the list. If not:
        //          Increase the size of the pairs list and add it to it.
        // In the end, loop thru all the pairs and print out their indexes
    
    
    return 0;
}

double randPt(){
    return (rand() % MAX_VAL) + MIN_VAL;
}


/**
Description: Takes in the list of all currently saved pairs and its size. It also takes in a value of a pair. The point of the function is to check if the pair exists inside the saved pairs regardless of form. So if the P1 = {x, y} and P2 = {y, x} the function will return true because it is analyzing whether or not the pair exists at all, regardless of order.

Parameters: 
            (Pair) pairs list
            (int) size of list
            (Pair) pair to check
            
Return: 
            (True) if the pairing exists in any form
            (False) if the pairing doesn't exist
Notes:
**/
bool hasPair(Pair *pairs, int size, Pair p){
    // In reality, instead of comparing the values of the spheres coordinates and such,
    // you can just see if the indexes stored in each struct are the same. 
    // However curiosity got the best of me so I began experimenting down a different route. 
    // This cost me time and I didn't finish. Don't be me.
    for(int i = 0; i < size; i++){
        Pair pair = pairs[i];
        
        // There spheres located in the pair we currently have selected
        Sphere p1s1 = pair.p1;
        Sphere p1s2 = pair.p2;
        
        // The spheres located into the pair we are given in the parameter
        Sphere p2s1 = p.p1;
        Sphere p2s2 = p.p2;
        
        /**
        POSSIBILITIES:
        
        p1s1 \ / p2s1
              x
        p1s2 / \ p2s2
        
        ---OR---
        
        p1s1 -- p2s1
        
        p1s2 -- p2s2
    
        **/
    
          // Possibility 1                   //Possibility 2  
        if((p1s1.isEqual(p2s2) && p1s2.isEqual(p2s1)) || (p1s1.isEqual(p2s1) && p1s2.isEqual(p2s2))) return true;
        
    }
    return false;
}
