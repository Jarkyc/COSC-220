#ifndef STOCKDAY_H
#define STOCKDAY_H
/*
Author: Charles Reigle
Creation Date: 3/13/2023
Last Update: 3/13/2023
Description: Structure and layout of the StockDay class
Notes:
*/

#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;

class StockDay{

private:
    Date date;
    double open;
    double close;
    double adjClose;
    double high;
    double low;
    double volume;
public:
    StockDay();
    StockDay(Date, double, double, double, double, double, double);
    void setData(Date, double, double, double, double, double, double);
    Date getDate();
    double getOpen();
    double getClose();
    double getAdjClose();
    double getHigh();
    double getLow();
    double getVolume();
    friend ostream &operator << (ostream&, StockDay&);

};

#endif
