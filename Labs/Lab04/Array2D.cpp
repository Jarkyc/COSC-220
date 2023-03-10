/**
Author: Charles Reigle
Creation Date: 2/23/23
Last Update: 2/23/23
Description: Implementation of the two dimensional array class
Notes: 
**/

#include "Array2D.h"

using namespace std;

/**
Description: Array2D constructor. Creates a dynamic array of pointers, which point to arrays, creating a   
             2D array
Parameters: 
            (int) r: rows
            (int) c: columns
            (int) defval: default value to be assigned at every index. prevents random garbage
Return: 
            None
Notes: 
**/
Array2D::Array2D(int r, int c, int defval){
    rows = r;
    cols = c;
    
    A = new int* [rows];
    for(int i = 0; i < rows; i++){
        A[i] = new int[cols];
        for(int k = 0; k < cols; k++){
            A[i][k] = defval;
        }
    }
}

/**
Description: Array2D Deconstructor. Frees up all the memory by deallocating everything.
Parameters:     
            None
Return: 
            None
Notes: 
**/
Array2D::~Array2D(){
    for(int i = 0; i < rows; i++){
        delete[] A[i];
    }
    delete[] A;
    A = nullptr;
}

/**
Description: Outputs the 2D array in a grid format to the console
Parameters: 
            None
Return: 
            None
Notes:
**/
void Array2D::display(){
 
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
int Array2D::getRows(){
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
int Array2D::getCols(){
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
void Array2D::set(int r, int c, int x){
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
int Array2D::get(int r, int c){
    if (r > rows - 1|| c > cols - 1){
        cout << "Index out of bounds. Max index: ";
        cout << "(" << rows - 1 << "x" << cols - 1 << ")" << endl;
        return 0;
    }
    
    return A[r][c];
}
