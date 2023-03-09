/*
Author: Charles Reigle
Creation Date: 3/9/23
Last Update: 3/9/23
Description: Structure and layout of the CustomerData class, child class of PersonData
Notes: 
*/

#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include "PersonData.h"

using namespace std;

//                   Child class of PersonData
class CustomerData : public PersonData{
private:
    int customerNumber;
    bool mailingList;
public:
    int getCustomerNumber();
    bool getMailingList();
    void setCustomerNumber(int);
    void setMailingList(bool);
    
    string getRecord();
    void PrintRecord();
    
};

#endif
