/**
Author: Charles Reigle
Creation Date: 2/23/23
Last Update: 2/23/23
Description: Implementation of the two dimensional array class
Notes: 
**/

#include "Matrix.h"

using namespace std;

/**
Description: Matrix constructor. Creates a dynamic array of pointers, which point to arrays, creating a
             2D array
Parameters: 
            (int) r: rows
            (int) c: columns
            (int) defval: default value to be assigned at every index. prevents random garbage
Return: 
            None
Notes: 
**/
Matrix::Matrix(int r, int c, int defval){
    rows = r;
    cols = c;
    
    A = new double* [rows];
    for(int i = 0; i < rows; i++){
        A[i] = new double[cols];
        for(int k = 0; k < cols; k++){
            A[i][k] = defval;
        }
    }
}

Matrix::Matrix(const Matrix &old){
    rows = old.rows;
    cols = old.cols;

    A = old.A;
}

/**
Description: Matrix Deconstructor. Frees up all the memory by deallocating everything.
Parameters:     
            None
Return: 
            None
Notes: 
**/
Matrix::~Matrix(){
    for(int i = 0; i < rows; i++){
        delete[] A[i];
    }
    delete[] A;
    A = nullptr;
}

Matrix& Matrix::operator =(const Matrix &m){
    rows = m.rows;
    cols = m.cols;

    for(int i = 0; i < rows; i++){
        delete[] A[i];
    }
    delete[] A;
    A = m.A;

    return *this;
}

Matrix Matrix:: operator +(const Matrix &b){
    Matrix m(1, 1, 0)
    if(rows == b.rows && cols == b.cols){
        m

    }
    return m;
}

/**
Description: Outputs the 2D array in a grid format to the console
Parameters: 
            None
Return: 
            None
Notes:
**/
void Matrix::display(){
 
    for(int i = 0; i < rows; i++){
        for(int k = 0; k < cols; k++){
            cout << A[i][k] << " ";
        }
        cout << endl;
    }
}

/**
Description: Gives the value of how many rows are in the array.
Parameters: 
            None
Return: 
            (int) rows: Amount of rows in the array
Notes: This returns the amount as a counting number, meaning if you try and access the last index using 
       this, it will be out of bounds since indexes start at 0 and counting numbers start at 1.
**/
int Matrix::getRows(){
    return rows;
}

/**
Description: Gives the value of how many columns are in the array.
Parameters: 
            None
Return: 
            (int) cols: Amount of columns in the array
Notes: This returns the amount as a counting number, meaning if you try and access the last index using 
       this, it will be out of bounds since indexes start at 0 and counting numbers start at 1.
**/
int Matrix::getCols(){
    return cols;
}

/**
Description: Sets the value of the array at the given indicies
Parameters: 
            (int) r: Row index of value (think x value)
            (int) c: Column index of value (think y value)
            (int) x: The value for the position to be set to
Return: 
            None
Notes: 
**/
void Matrix::set(int r, int c, double x){
    if (r > rows - 1|| c > cols - 1){
        cout << "Index out of bounds. Max index: ";
        cout << "(" << rows - 1 << "x" << cols - 1 << ")" << endl;
        return;
    }
    
    A[r][c] = x;
}

/**
Description: Returns the value that it is at the given index
Parameters: 
            (int) r: Row index of the value (think x value)
            (int) c: Column index of the value (think y value)
Return: 
            (int) x: The value stored at the given coordinates 
Notes: 
**/
double Matrix::get(int r, int c){
    if (r > rows - 1|| c > cols - 1){
        cout << "Index out of bounds. Max index: ";
        cout << "(" << rows - 1 << "x" << cols - 1 << ")" << endl;
        return 0;
    }
    
    return A[r][c];
}
