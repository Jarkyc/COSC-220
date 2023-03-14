/*
Author: Charles Reigle
Creation Date: 3/13/2023
Last Update: 3/13/2023
Description: Structure and layout of the StockList class
Notes:
*/

#ifndef STOCKLIST_H
#define STOCKLIST_H

#include <iostream>
#include "StockDay.h"
#include "Date.h"

using namespace std;

class StockList{
private:
    StockDay* list = nullptr;
    int size;
    int capacity;
    bool isValid(int);
    void IncreaseCapacity();
public:
    StockList(int c = 2);
    StockList(const StockList&);
    ~StockList();
    void setElement(int, StockDay);
    StockDay getElement(int);
    void displayList();
    void append(StockDay);
    int getSize();
    int getCapacity();
    int find(Date);
    void operator = (StockList&);
    StockDay* operator [] (int);
    friend ostream &operator << (ostream&, StockList&);



};

#endif
