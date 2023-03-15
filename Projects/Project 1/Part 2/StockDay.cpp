/*
Author: Charles Reigle
Creation Date: 3/13/2023
Last Update: 3/13/2023
Description: Implementation of the StockDay class
Notes:
*/

#include "StockDay.h"

using namespace std;

/*
Description: Default Constructor
Parameters:
            None
Return:
            None
Notes:
*/
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

/*
Description: Overloaded Constructor
Parameters:
            (Date) day: Date of Stock
            (double) op: Open value
            (double) cl: Close value
            (double) adjcl: Adjusted close value
            (double) hi: High value
            (double) lw: Low value
            (double) vol: Volume
Return:
            None
Notes:
*/
StockDay::StockDay(Date day, double op, double cl, double adjcl, double hi, double lw, double vol){
    date = day;
    open = op;
    close = cl;
    adjClose = adjcl;
    high = hi;
    low = lw;
    volume = vol;
}

/*
Description: Sets all the data to the new parameters
Parameters:
            (Date) day: Date of Stock
            (double) op: Open value
            (double) cl: Close value
            (double) adjcl: Adjusted close value
            (double) hi: High value
            (double) lw: Low value
            (double) vol: Volume
Return:
            None
Notes:
*/
void StockDay::setData(Date day, double op, double cl, double adjcl, double hi, double lw, double vol){
    date = day;
    open = op;
    close = cl;
    adjClose = adjcl;
    high = hi;
    low = lw;
    volume = vol;
}

/*
Description: returns the stored Date value
Parameters:
            None
Return:
            (Date) d: Date stored
Notes:
*/
Date StockDay::getDate(){
    return date;
}

/*
Description: returns the stored Open value
Parameters:
            None
Return:
            (Double) open: Open value
Notes:
*/
double StockDay::getOpen(){
    return open;
}

/*
Description: returns the stored Close value
Parameters:
            None
Return:
            (Double) close: Close value
Notes:
*/
double StockDay::getClose(){
    return close;
}

/*
Description: returns the stored Adjusted Close value
Parameters:
            None
Return:
            (Double) adjClose: Adjusted Close value
Notes:
*/
double StockDay::getAdjClose(){
    return adjClose;
}

/*
Description: returns the stored High value
Parameters:
            None
Return:
            (Double) high: High value
Notes:
*/
double StockDay::getHigh(){
    return high;
}

/*
Description: returns the stored Low value
Parameters:
            None
Return:
            (Double) low: Low value
Notes:
*/
double StockDay::getLow(){
    return low;
}

/*
Description: returns the stored Volume value
Parameters:
            None
Return:
            (Double) volume: Volume value
Notes:
*/
double StockDay::getVolume(){
    return volume;
}

/*
Description: Overloaded stream insertion operator
Parameters:
            (ostream) stream: Stream to be inserted to
            (StockDay) sd: StockDay to insert
Return:
            (ostream) stream: Stream inserted into
Notes:
*/
ostream &operator << (ostream &stream, StockDay &sd){
    stream << fixed;
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
