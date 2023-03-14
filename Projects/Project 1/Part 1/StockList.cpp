/*
Author: Charles Reigle
Creation Date: 3/13/2023
Last Update: 3/14/2023
Description: Implementation of the StockList class
Notes:
*/

#include "StockList.h"

using namespace std;

StockList::StockList(int c){
    capacity = c;
    size = 0;

    list = new StockDay[capacity];
}

StockList::StockList(const StockList &sl){
    capacity = sl.capacity;
    size = sl.size;

    list = new StockDay[capacity];
    for(int i = 0; i < size; i++){
        list[i] = sl.list[i];
    }
}

StockList::~StockList(){
    delete[] list;
    list = nullptr;
}


void StockList::operator = (StockList &sl){
    StockDay* newList = sl.list;
    delete[] list;
    list = newList;
    size = sl.size;
    capacity = sl.capacity;
    newList = nullptr;
}

int StockList::getSize(){
    return size;
}

int StockList::getCapacity(){
    return capacity;
}

void StockList::setElement(int i, StockDay sd){
    if(isValid(i)){
        list[i] = sd;
    }
}

StockDay StockList::getElement(int i){
    if(isValid(i)){
        StockDay sd;
        return sd;
    } else {
        return list[i];
    }
}

int StockList::find(Date d){
    for(int i = 0; i < size; i++){
        if(d == list[i].getDate()) return i;
    }
    return -1;
}

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

void StockList::append(StockDay sd){
    if(size == capacity) IncreaseCapacity();
    list[size] = sd;
    size++;
}


void StockList::displayList(){
// Loop thru each stockday
    for(int i = 0; i <size; i++){
        cout << list[i] << endl;
        cout << "-----------------------------------" << endl;
    }

}


StockDay* StockList::operator [] (int i){
    if(i >= size || i < 0) return nullptr;
    return &(list[i]);
}

bool StockList::isValid(int i){
    return ((i < size - 1) && (i > -1));
}

ostream &operator << (ostream &stream, StockList &list){
    list.displayList();
    return stream;
}

