/*
Author: Charles Reigle
Creation Date: 3/13/2023
Last Update: 3/13/2023
Description: Implementation of the date class
Notes:
*/

#include "Date.h"
#include <sstream>

using namespace std;

/*
Description: Default constructor for a date object
Parameters:
            None
Return:
            None
Notes:
*/
Date::Date(){
    month = -1;
    day = -1;
    year = -1;
}


/*
Description: Overloaded constructor for date object
Parameters:
            (int) m: Month
            (int) d: Day
            (int) y: Year
Return:
            None
Notes:
*/
Date::Date(int m, int d, int y){
    month = m;
    day = d;
    year = y;
}

/*
Description: Sets the date to the new paramteres
Parameters:
            (int) m: Month
            (int) d: Day
            (int) y: Year
Return:
            None
Notes:
*/
void Date::setDate(int m, int d, int y){
    month = m;
    day = d;
    year = y;
}

/*
Description: Returns the date in a string format
Parameters:
            None
Return:
            (string): Month/Day/Year
Notes:
*/
string Date::getDate(){
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}

/*
Description: Overloaded equal operator
Parameters:
            (Date) d: The date being compared to (right side)
Return:
            (bool): Whether or not the dates are equal
Notes:
*/
bool Date::operator == (const Date &d){
    return year == d.year && month == d.month && day == d.day;
}

/*
Description: Overloaded greater than operator
Parameters:
            (Date) d: The date being compared to (right side)
Return:
            (bool): Whether or not the date on the left comes after the date on the right
Notes:
*/
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

/*
Description: Overloaded less than operator
Parameters:
            (Date) d: The date being compared to (right side)
Return:
            (bool): Whether or not the dates on the left comes before the date on the right
Notes:
*/
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

/*
Description: Overloaded greater than or equal to operator
Parameters:
            (Date) d: The date being compared to (right side)
Return:
            (bool): Whether or not the date on the left comes before or is equal to the one on the right
Notes:
*/
bool Date::operator >= (const Date &d){
    return (*this > d || *this == d);
}

/*
Description: Overloaded less than or equal to operator
Parameters:
            (Date) d: The date being compared to (right side)
Return:
            (bool): Whether or not the date on the left comes after or is equal to the one on the right
Notes:
*/
bool Date::operator <= (const Date &d){
    return (*this < d || *this == d);
}

/*
Description: Overloaded not equal operator
Parameters:
            (Date) d: The date being compared to (right side)
Return:
            (bool): Whether or not the date on the left is NOT equal to the one on the right
Notes:
*/
bool Date::operator != (const Date &d){
    return !(*this == d);
}

/*
Description: Overloaded stream insertion operator
Parameters:
            (ostream) stream: stream being inserted into
            (Date) d: date being inserted
Return:
            (ostream) stream: the stream being inserted into
Notes:
*/
ostream &operator << (ostream &stream, Date &d){
    stream << d.getDate();
    return stream;
}

//TODO - Comment
void Date::setMDY(string str){
    stringstream s(str);

    string m;
    string d;
    string y;

    getline(s, m, '/');
    getline(s, d, '/');
    getline(s, y);

    month = stoi(m);
    day = stoi(d);
    year = stoi(y);
}

//TODO - Comment
string Date::toString(){
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}
