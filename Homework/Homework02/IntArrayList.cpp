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
    if((index <= size) && index > -1){
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
    return size;
}

/**
Description: Displays the address of the list being stored
Parameters:
            None
Return:
            None
Notes:
**/
void IntArrayList::displayAddress(){
    cout << list << endl;
}

/**
Description: Bubble sorts the array int ascending order
Parameters:
            None
Return:
            None
Notes:
**/
void IntArrayList::sort(){
    bool chg = true;

    while(chg) {
        chg = false;
        for(int i = 0; i < size - 1; i++) {
            if(list[i] > list[i + 1]) {
                int temp = list[i+1];
                list[i + 1] = list[i];
                list[i] = temp;
                chg = true;
            }
        }
    }
}

/**
Description: Returns whether or not the array is sorted in ascending order
Parameters:
            None
Return:
            None
Notes:
**/
bool IntArrayList::sorted(){
 for(int i = 0; i < size - 1; i++) {
        if(list[i] > list[i + 1]) {
            return false;
        }
    }
    return true;
}

/**
Description: Gets the value stored at the input index
Parameters:
            (int) index: index to check
Return:
        None
Notes:
**/
int IntArrayList::get(int index){
    return list[index];
}

/**
Description: Concatanates the input array onto the end of the current array
Parameters:
            (IntArrayList) arr: array to be added
Return:
            None
Notes:
**/
void IntArrayList::concat(IntArrayList &arr){
    int newSize = size + arr.length();

    int* newList = new int[newSize];

    for(int i = 0; i < size; i++){
        newList[i] = list[i];
    }

    for(int i = 0; i < arr.length(); i++){
        newList[i + size] = arr.get(i);
    }

    delete[] list;
    list = newList;

    newList = nullptr;

    size = newSize;
}

/**
Description: Removes everything in the given bounds, excluding the upper bounds
Parameters:
            (int) lower: Lower bound
            (int) upper: upper bound
Return:
            None
Notes:
**/
void IntArrayList::remove(int lower, int upper){

    if(upper - lower + 1== size){
        delete[] list;
        list = nullptr;
    }

    if(lower < 0) lower = 0;
    if(upper > size) upper = size - 1;

    int removedSize = upper - lower;

    int newSize = size - removedSize;
    int* newArr = new int[newSize];
    for(int i = 0; i < lower; i++){
        newArr[i] = list[i];
    }

    for(int i = 0; i < size - upper; i++){
        newArr[lower + i] = list[i + upper];
    }


    delete[] list;
    list = newArr;
    newArr = nullptr;
    size = newSize;
}

/**
Description: Randomly shuffles the array
Parameters:
            None
Return:
            None
Notes:
**/
void IntArrayList::shuffle(){
    int* begin = &list[0];
    int* end = &list[size];

    random_shuffle(begin, end);
}

/**
Description: Rewrites the list to be a sub array, with the sub array being the information between the input parameters
Parameters:
            (int) begin: beginning index to start at
            (int) end: ending bound to stop at
Return:
            None
Notes:
**/
void IntArrayList::sub(int begin, int end){
    if(begin < 0) begin = 0;
    if(end > size-1) end = size-1;

    int newSize = end - begin;
    int* newArr = new int[newSize];

    for(int i = 0; i < newSize; i++){
        newArr[i] = list[i + begin];
    }

    delete[] list;
    list = newArr;
    newArr = nullptr;
    size = newSize;
}

/**
Description: Inserts the given array into the current one, starting at the given index.
Parameters:
            (IntArrayList) arr: list to be inserted
            (int): index to insert at
Return:
            None
Notes:
**/
void IntArrayList::insert(IntArrayList &arr, int index){
    int newSize = size + arr.length();

    int* newArr = new int[newSize];
    int currPos = 0;
    for(int i = 0; i < index; i++){
        newArr[i] = list[i];
        currPos++;
    }

    for(int i = 0; i < arr.length(); i++){
        newArr[currPos] = arr.get(i);
        currPos++;
    }

    for(int i = 0; i < size - index; i++){
        newArr[currPos] = list[index + i];
        currPos++;
    }

    delete[] list;
    list = newArr;
    newArr = nullptr;
    size = newSize;

}

/**
Description: Inserts the given value at the specified index
Parameters:
            (int) val: value to be inserted
            (int) index: index to be inserted at
Return:
            None
Notes:
**/
void IntArrayList::insert(int val, int index){

    if(index < 0) index = 0;
    if(index > size -1) index = size;

    int newSize = size + 1;

    int* newArr = new int[newSize];
    int currPos = 0;
    for(int i = 0; i < index; i++){
        newArr[i] = list[i];
        currPos++;
    }
    newArr[index] = val;
    currPos++;

    for(int i = 0; i < size - index; i++){
        newArr[currPos] = list[index + i];
        currPos++;
    }

    delete[] list;
    list = newArr;
    newArr = nullptr;
    size = newSize;
}
