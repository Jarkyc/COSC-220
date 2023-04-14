/*
Author: Charles Reigle
Creation Date: 3/16/23
Last Update: 3/16/23
Description: Structure and layout of the PreferredCustomer class, child class of CustomerData
Notes:
*/

#ifndef PREFERREDCUSTOMER_H
#define PREFERREDCUSTOMER_H

#include "CustomerData.h"

using namespace std;

class PreferredCustomer : public CustomerData{
private:
    double purchaseAmount;
    double discount;
public:
    PreferredCustomer(string, string, string, string, string, string, string, int, bool, double);
    double getPurchaseAmount();
    double getDiscount();

    string getRecord();
    void PrintRecord();

};

#endif
