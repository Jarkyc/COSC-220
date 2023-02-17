/**
Author: Charles Reigle
Creation Date: 2/16/23
Last Update: 2/16/23
Description: IntArrayList implementation and functions
Notes:
**/

#include "IntArrayList.h"

using namespace std;


/**
Description: Constructor sets the size to 0 and create a dynamic array
Parameters: None
Return: None
Notes:
**/
IntArrayList::IntArrayList(){
    size = 0;
    list = new int[0];
}


/**
Description: Deconstructor deallocates all memory
Parameters: None
Return: None
Notes:
**/
IntArrayList::~IntArrayList(){
    delete[] list;
    list = nullptr;
}

/**
Description: Appends a value onto the end of the stored dynamic array
Parameters:
            (int) n: number to be appended
Return: None
Notes:
**/
void IntArrayList::add(int n){
    int newSize = size + 1;
    int *newList = new int[newSize];

    for(int i = 0; i < size; i++){
        newList[i] = list[i];
    }

    newList[size] = n;

    delete[] list;
    list = newList;

    newList = nullptr;

    size = newSize;

}


/**
Description: Duplicates the current array into the array passed in the parameters
Parameters:
            (IntArrayList): Variable to be duplicated into
Return: None
Notes:
**/
void IntArrayList::duplicate(IntArrayList &l2){
    l2.resize(size);

    for(int i = 0; i < size; i++){
        l2.set(i, list[i]);
    }
}


/**
Description: Sets the value at the given index to n
Parameters:
            (int) index: position to override
            (int) n: new value
Return: None
Notes:
**/
void IntArrayList::set(int index, int n){
    if((index <= size) && index > 0){
        list[index] = n;
    }
}


/**
Description: Displays the values stored in the list to console
Parameters:
            (bool) vert: Whether or not the display should be vertical or horizontal
Return: None
Notes:
**/
void IntArrayList::display(bool vert){
    for(int i = 0; i < size; i++){
        cout << list[i];
        if(vert) cout << endl;
        else cout << " ";
    }
    cout << endl;
}


/**
Description: Resizes the array to the given size. Truncates the array if it shrinks.
Parameters:
            (int) n: new size
Return: None
Notes:
**/
void IntArrayList::resize(int n){
    int *newList = new int[n];

    for(int i = 0; i < n; i++){
        if(i < size) newList[i] = list[i];
        else newList[i] = 0;
    }

    delete[] list;
    list = newList;

    newList = nullptr;

    size = n;
}


/**
Description: Returns the size of the array
Parameters: None
Return:
        (int) length
Notes:
**/
int IntArrayList::length(){
    return filled;
}
