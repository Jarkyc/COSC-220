/**
Author: Charles Reigle
Creation Date: 2/23/23
Last Update: 3/31/23
Description: Structure of the two dimensional array class
Notes: 
**/

#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

template <class T>
class Array2D{

private:
    vector<vector<T>> A;
    int rows;
    int cols;
    T defval;
public:
    Array2D(int r, int c, T def);
    Array2D(const Array2D&);
    Array2D& operator=(Array2D&);
    //~Array2D();
    
    int getRows();
    int getCols();
    void set(int, int, T);
    T get(int, int) const;
    void resize(int r = 3, int c = 3);
    void display(int x = 1);
    vector<T> operator[](int);
    bool operator== (const Array2D&);
    bool operator != (const Array2D&);

    template <class U>
    friend ostream& operator << (ostream&, const Array2D<U>&);

};

#endif

/**
Description: Array2D constructor. Creates a dynamic array of pointers, which point to arrays, creating a
             2D array
Parameters:
            (int) r: rows
            (int) c: columns
            (T) defval: default value to be assigned at every index. prevents random garbage
Return:
            None
Notes:
**/
template <class T>
Array2D<T>::Array2D(int r, int c, T def){
    rows = r;
    cols = c;
    defval = def;

    //A = vector<vector<T>>();
    for(int i = 0; i < rows; i++){
        vector<T> b;
        A.push_back(b);
        for(int k = 0; k < cols; k++){
            A.at(i).push_back(defval);
        }
    }
}

/**
Description: Array2D copy constructor

Parameters:
            const (Array2D) &arr: Array to copy
Return:
            None
Notes:
**/
template <class T>
Array2D<T>::Array2D(const Array2D<T> &arr){
    rows = arr.rows;
    cols = arr.cols;
    defval = arr.defval;

    A = vector<vector<T>>();
    for(int i = 0; i < rows; i++){
        vector<T> b;
        A.push_back(b);
        for(int k = 0; k < cols; k++){
            A.at(i).push_back(arr.A.at(i).at(k));
        }
    }
}

/**
Description: Overloaded assignment operator
Parameters:
            const (Array2D) &arr: Array to copy from
Return:
            None
Notes:
**/
template <class T>
Array2D<T>& Array2D<T>::operator =(Array2D<T> &arr){
    rows = arr.rows;
    cols = arr.cols;
    defval = arr.defval;

    A = vector<vector<T>>();
    for(int i = 0; i < rows; i++){
        vector<T> b;
        A.push_back(b);
        for(int k = 0; k < cols; k++){
            A.at(i).push_back(arr.A.at(i).at(k));
        }
    }
    return *this;
}


/**
Description: Array2D Deconstructor. Frees up all the memory by deallocating everything.
Parameters:
            None
Return:
            None
Notes:
**/
/*
template <class T>
Array2D<T>::~Array2D(){
    for(int i = 0; i < rows; i++){
        delete[] A[i];
    }
    delete[] A;
    A = nullptr;
}
*/
/**
Description: Displays the array in a grid fomat, with a width buffer for each element of the input width
Parameters:
            (int) x: width
Return:
            None
Notes:
**/
template <class T>
void Array2D<T>::display(int x){
    if (x < 0) x = 1;
    for(int i = 0; i < rows; i++){
        for(int k = 0; k < cols; k++){
            cout <<  A[i][k];
            for(int s = 0; s < x; s++){
                cout << " ";
            }
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
template <class T>
int Array2D<T>::getRows(){
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
template <class T>
int Array2D<T>::getCols(){
    return cols;
}

/**
Description: Sets the value of the array at the given indicies
Parameters:
            (int) r: Row index of value (think x value)
            (int) c: Column index of value (think y value)
            (T) x: The value for the position to be set to
Return:
            None
Notes:
**/
template <class T>
void Array2D<T>::set(int r, int c, T x){
    if (r > rows - 1|| c > cols - 1){
        cout << "Index out of bounds. No changes made to the array." << endl;
        return;
    }

    A.at(r).at(c) = x;
}

/**
Description: Returns the value that it is at the given index
Parameters:
            (int) r: Row index of the value (think x value)
            (int) c: Column index of the value (think y value)
Return:
            (T) x: The value stored at the given coordinates
Notes:
**/
template <class T>
T Array2D<T>::get(int r, int c) const{
    return A.at(r).at(c);
}

/**
Description: Resizes the array, keeping any info it had stored if the new sizes are bigger than the old one. Truncates the array if the new sizes are smaller than the
             last
Parameters:
            (int) r: New rows size
            (int) c: New columns size
Return:
            None
Notes:
**/
template <class T>
void Array2D<T>::resize(int r, int c){
    if(r < 1) r = 1;
    if(c < 1) c = 1;

    vector<vector<T>> list;
    for(int i = 0; i < r; i++){
        vector<T> b;
        list.push_back(b);
        for(int k = 0; k < c; k++){
            // If the rows exist in the old array, bring them over.
            // They can only exist if we are in cells within the old arrays bounds
            if(i < rows && k < cols){
                list.at(i).push_back(A.at(i).at(k));
            // Otherwise populate it with the default value
            } else list.at(i).push_back(defval);
        }
    }

    A = list;

    rows = r;
    cols = c;

}

/**
Description: Overloaded bracket operator
Parameters:
            (int) v: index of vector to retrieve
Return:
            (vector): vector at index
Notes:
**/
template <class T>
vector<T> Array2D<T>::operator [](int v){
    return A[v];
}

/**
Description: Overloaded equal operator
             last
Parameters:
            const (Array2D) &arr: Array2D to compare to
Return:
            (bool): whether or not the vectors are equal
Notes:
**/
template <class T>
bool Array2D<T>::operator== (const Array2D<T> &arr){
    if(rows != arr.rows || cols != arr.cols) return false;

    for(int i = 0; i < rows; i++){
        for(int k = 0; k < cols; k++){
            if(A.at(i).at(k) != arr.A.at(i).at(k)) return false;
        }
    }
    return true;
}

/**
Description: Overloaded not equal to operator
Parameters:
            const (Array2D) &arr: Array2D to compare to
Return:
            (bool): whether or not the arrays are NOT equal to eachother
Notes:
**/
template <class T>
bool Array2D<T>::operator!= (const Array2D<T> & arr){
    return !(*this == arr);
}

/**
Description: Overloaded stream insertion operator
Parameters:
            (ostream) &strm: stream to insert into
            const (Array2D) &obj: object to print out
Return:
            (ostream) &strm: stream inserted into
Notes:
**/
template <class T>
ostream& operator << (ostream &strm, const Array2D<T> &obj){
    strm << "[";
    for(int i = 0; i < obj.rows; i++){
        strm << "[";
        for(int k = 0; k < obj.cols; k++){
            strm << obj.get(i, k);
            if(k < obj.cols-1) strm << " ";
        }
        strm << "]";
    }
    strm << "]";
    return strm;

}
