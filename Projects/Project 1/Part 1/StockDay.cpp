/*
Author: Charles Reigle
Creation Date: 3/13/2023
Last Update: 3/13/2023
Description: Implementation of the StockDay class
Notes:
*/

#include "StockDay.h"

using namespace std;

StockDay::StockDay(){
    Date dt;
    date = dt;
    open = 0.0;
    close = 0.0;
    adjClose = 0.0;
    high = 0.0;
    low = 0.0;
    volume = 0;
}

StockDay::StockDay(Date day, double op, double cl, double adjcl, double hi, double lw, int vol){
    date = day;
    open = op;
    close = cl;
    adjClose = adjcl;
    high = hi;
    low = lw;
    volume = vol;
}

void StockDay::setData(Date day, double op, double cl, double adjcl, double hi, double lw, int vol){
    date = day;
    open = op;
    close = cl;
    adjClose = adjcl;
    high = hi;
    low = lw;
    volume = vol;
}

Date StockDay::getDate(){
    return date;
}

double StockDay::getOpen(){
    return open;
}

double StockDay::getClose(){
    return close;
}

double StockDay::getAdjClose(){
    return adjClose;
}

double StockDay::getHigh(){
    return high;
}

double StockDay::getLow(){
    return low;
}

int StockDay::getVolume(){
    return volume;
}

ostream &operator << (ostream &stream, StockDay &sd){
    stream << setw(12) << left << "Date:";
    stream << sd.date << endl;

    stream << setw(12) << left << "Open:";
    stream << sd.open << endl;

    stream << setw(12) << left << "Close:";
    stream << sd.close << endl;

    stream << setw(12) << left << "Adj. Close:";
    stream << sd.adjClose << endl;

    stream << setw(12) << left << "High:";
    stream << sd.high << endl;

    stream << setw(12) << left << "Low:";
    stream << sd.low << endl;

    stream << setw(12) << left << "Volume:";
    stream << sd.volume;

    return stream;
}
