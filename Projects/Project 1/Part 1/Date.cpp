/*
Author: Charles Reigle
Creation Date: 3/13/2023
Last Update: 3/13/2023
Description: Implementation of the date class
Notes:
*/

#include "Date.h"

using namespace std;

Date::Date(){
    month = -1;
    day = -1;
    year = -1;
}

Date::Date(int m, int d, int y){
    month = m;
    day = d;
    year = y;
}

void Date::setDate(int m, int d, int y){
    month = m;
    day = d;
    year = y;
}

string Date::getDate(){
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}

bool Date::operator == (const Date &d){
    return year == d.year && month == d.month && day == d.day;
}

bool Date::operator > (const Date &d){
    if(year > d.year){
        return true;
    } else if(year == d.year){
        if(month > d.month){
            return true;
        } else if(month == d.month && day > d.day) return true;
        else return false;
    } else return false;
}

bool Date::operator < (const Date &d){
    if(d.year > year){
        return true;
    } else if(d.year == year){
        if(d.month > month){
            return true;
        } else if(d.month == month && d.day > day) return true;
        else return false;
    } else return false;
}

bool Date::operator >= (const Date &d){
    return (*this > d || *this == d);
}

bool Date::operator <= (const Date &d){
    return (*this < d || *this == d);
}

bool Date::operator != (const Date &d){
    return !(*this == d);
}

ostream &operator << (ostream &stream, Date &d){
    stream << d.getDate();
    return stream;
}
