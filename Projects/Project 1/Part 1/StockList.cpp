/*
Author: Charles Reigle
Creation Date: 3/13/2023
Last Update: 3/14/2023
Description: Implementation of the StockList class
Notes:
*/

#include "StockList.h"

using namespace std;

/*
Description: Overloaded constructor
Parameters:
            (int) c: Capacity of the list (default 10)
Return:
            None
Notes:
*/
StockList::StockList(int c){
    capacity = c;
    size = 0;

    list = new StockDay[capacity];
}

/*
Description: Copy constructor
Parameters:
            (StockList) sl: StockList to copy
Return:
            None
Notes:
*/
StockList::StockList(const StockList &sl){
    capacity = sl.capacity;
    size = sl.size;

    list = new StockDay[capacity];
    for(int i = 0; i < size; i++){
        list[i] = sl.list[i];
    }
}

/*
Description: Deconstructor that deletes all dynamic data
Parameters:
            None
Return:
            None
Notes:
*/
StockList::~StockList(){
    delete[] list;
    list = nullptr;
}

/*
Description: Overloaded assignment operator
Parameters:
            (StockList) sl: The stock list to be assigned
Return:
            None
Notes:
*/
void StockList::operator = (StockList &sl){
    StockDay* newList = sl.list;
    delete[] list;
    list = newList;
    size = sl.size;
    capacity = sl.capacity;
    newList = nullptr;
}

/*
Description: The current size of the data being stored
Parameters:
            None
Return:
            (int) size: Amount of data
Notes:
*/
int StockList::getSize(){
    return size;
}

/*
Description: The max capacity of the current list
Parameters:
            None
Return:
            (int) capacity: Max capacity of the list
Notes:
*/
int StockList::getCapacity(){
    return capacity;
}

/*
Description: Sets the element at the index given, after checking if it is a valid index
Parameters:
            (int) i: Index to insert to
            (StockDay) sd: The StockDay object to insert
Return:
            None
Notes:
*/
void StockList::setElement(int i, StockDay sd){
    if(isValid(i)){
        list[i] = sd;
    }
}

/*
Description: Returns the element at the given index, after checking if the index exists
Parameters:
            (int) i: index
Return:
            (StockDay) sd: StockDay at the index;
Notes:
*/
StockDay StockList::getElement(int i){
    if(isValid(i)){
        StockDay sd;
        return sd;
    } else {
        return list[i];
    }
}

/*
Description: Finds the index of the input date, if it exists. If it doesn't exist, returns -1
Parameters:
            (Date) d: Date to look for
Return:
            (int) i: index;
Notes:
*/
int StockList::find(Date d){
    for(int i = 0; i < size; i++){
        if(d == list[i].getDate()) return i;
    }
    return -1;
}

/*
Description: Doubles the max capacity of the list, creates a new list, and update the current one after transfering all the data
Parameters:
            None
Return:
            None
Notes:
*/
void StockList::IncreaseCapacity(){
    capacity *= 2;
    // Create a new list
    StockDay* newList = new StockDay[capacity];
    for(int i = 0; i < size; i++){
        newList[i] = list[i];
    }
    delete[] list;
    list = newList;

    newList = nullptr;
}

/*
Description: Adds a new value to the end of the list
Parameters:
            (StockDay) sd: StockDay to insert
Return:
            None
Notes:
*/
void StockList::append(StockDay sd){
    if(size == capacity) IncreaseCapacity();
    list[size] = sd;
    size++;
}

/*
Description: Displays the statistics of every StockDay in the list
Parameters:
            None
Return:
            None
Notes:
*/
void StockList::displayList(){
// Loop thru each stockday
    for(int i = 0; i <size; i++){
        cout << list[i] << endl;
        cout << "-----------------------------------" << endl;
    }

}

/*
Description: Overloaded brack operator
Parameters:
            (int) i: index to access in the list
Return:
            (StockDay*) sd: Pointer to the StockDay stored in the list
Notes:
*/
StockDay* StockList::operator [] (int i){
    if(i >= size || i < 0) return nullptr;
    return &(list[i]);
}

/*
Description: Checks if the value given is a valid index in the list (if something is stored in it)
Parameters:
            (int) i: index to check
Return:
            (bool): Whether or not the index is a proper location
Notes:
*/
bool StockList::isValid(int i){
    return ((i < size - 1) && (i > -1));
}

/*
Description: Overloaded stream insertion operator
Parameters:
            (ostream) stream: stream to insert into
            (StockList) sl: list to insert
Return:
            (ostream) stream: stream inserted into
Notes:
*/
ostream &operator << (ostream &stream, StockList &list){
    for(int i = 0; i < list.size; i++){
        stream << (*list[i]) << endl;
        stream << "-----------------------------------" << endl;
    }
    return stream;
}

