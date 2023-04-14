/*
Author: Charles Reigle
Creation Date: 3/13/2023
Last Update: 4/12/2023
Description: Structure and layout of the date class
Notes:
*/
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date{
private:
    int month;
    int day;
    int year;
public:
    Date();
    Date(int, int, int);
    void setDate(int, int, int);
    void setMDY(string);
    string toString();
    string getDate();
    bool operator > (const Date&);
    bool operator < (const Date&);
    bool operator == (const Date&);
    bool operator >= (const Date&);
    bool operator <= (const Date&);
    bool operator != (const Date&);
    friend ostream &operator << (ostream&, Date&);


};

#endif
