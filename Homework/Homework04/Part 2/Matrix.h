/**
Author: Charles Reigle
Creation Date: 2/23/23
Last Update: 2/23/23
Description: Structure of the two dimensional array class
Notes:
**/

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Matrix{

private:
    double** A = nullptr;
    int rows;
    int cols;
public:
    Matrix(int r = 3, int c = 3, int defval = 0);
    Matrix(const Matrix&);
    ~Matrix();

    void display();
    void display(int);
    int getRows();
    int getCols();
    void set(int, int, double);
    double get(int, int) const;
    Matrix transpose();
    Matrix& operator = (const Matrix&);
    Matrix operator + (const Matrix&);
    Matrix operator - (const Matrix&);
    double* operator [](int);
    friend Matrix operator * (double, const Matrix&);
    friend Matrix operator * (const Matrix&, double);
    friend ostream& operator <<(ostream& , const Matrix&);
    void resize(int, int, double);
};

#endif
