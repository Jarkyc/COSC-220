/*
Author: Charles Reigle
Creation Date: 3/16/23
Last Update: 3/16/23
Description: Implementation of the PreferredCustomer class
Notes:
*/

#include "PreferredCustomer.h"
#include "CustomerData.h"
#include <string>

/*
Description: Customer Data constructor
Parameters:
            (string) f: First Name
            (string) l: Last Name
            (string) st: State
            (string) cit: City
            (string) adr: Address
            (string) ph: Phone Number
            (string) zp: Zip Code
            (int) num: Customer Number
            (bool) ml: If the person wants to be on the mailing list
            (double) spent: Customers purchase amount
Return:
            None
Notes:
*/
PreferredCustomer::PreferredCustomer(string f, string l, string st, string cit, string adr, string ph, string zp, int num, bool ml, double spent)
:CustomerData(f, l, st, cit, adr, ph, zp, num, ml){

    purchaseAmount = spent;
    if(spent >= 500 && spent < 1000) discount = 5.0;
    else if(spent >= 1000 && spent < 1500) discount = 6.0;
    else if(spent >= 1500 && spent < 2000) discount = 7.0;
    else if(spent >= 2000) discount = 10.0;
}

/*
Description: Returns a double of the customers purchase amount
Parameters:
            None
Return:
            (double) purchaseAmount: How much money the customer has spent
Notes:
*/
double PreferredCustomer::getPurchaseAmount(){
    return purchaseAmount;
}

/*
Description: Returns a double of the customers discount
Parameters:
            None
Return:
            (double) discount: value of the customers calculated discount
Notes:
*/
double PreferredCustomer::getDiscount(){
    return discount;
}

/*
Description: Returns a string of the customers data
Parameters:
            None
Return:
            (string) record: Formated string of the customers recorded info
Notes:
*/
string PreferredCustomer::getRecord(){
    string begin = CustomerData::getRecord();
    return begin + " / Account: $" + to_string(purchaseAmount) + " / Discount: " + to_string(discount) + "%";
}

/*
Description: Prints out the customers record in a list
Parameters:
            None
Return:
            None
Notes:
*/
void PreferredCustomer::PrintRecord(){
    CustomerData::PrintRecord();
    cout << "Purchase Amount: " << purchaseAmount << endl;
    cout << "Discount Level: " << discount << "%" << endl;
}
