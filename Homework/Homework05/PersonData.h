/*
Author: Charles Reigle
Creation Date: 3/9/23
Last Update: 3/9/23
Description: Structure and layout for the PersonData class
Notes: 
*/

#ifndef PERSONDATA_H
#define PERSONDATA_H

#include <iostream>
#include <string>

using namespace std;

class PersonData{
private:
    string lastName;
    string firstName;
    string state;
    string city;
    string address;
    string phone;
    string zip;
public:
    PersonData(string, string, string, string, string, string, string);
    string getLastName();
    string getFirstName();
    string getState();
    string getCity();
    string getAddress();
    string getPhone();
    string getZip();
    
    void setName(string, string);
    void setAddress(string, string, string, string);
    void setPhone(string);
    void setZip(string);
    
    virtual string getRecord();
    virtual void PrintRecord();
};

#endif
