/**
Author: Charles Reigle
Creation Date: 2/23/23
Last Update: 3/1/23
Description: Structure of the two dimensional array class
Notes: 
**/

#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <iostream>
#include <iomanip>

class Array2D{

private:
    int** A = nullptr;
    int rows;
    int cols;
public:
    Array2D(int r = 3, int c = 3, int defval = 0);
    ~Array2D();
    
    void display();
    int getRows();
    int getCols();
    void set(int, int, int);
    int get(int, int);
    void resize(int r = 3, int c = 3, int deval = 0);
    void display(int);
};

#endif
