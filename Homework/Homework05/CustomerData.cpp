/*
Author: Charles Reigle
Creation Date: 3/9/23
Last Update: 3/9/23
Description: Implementation of the CustomerData class
Notes: 
*/

#include "CustomerData.h"

using namespace std;

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
Return:
            None
Notes:
*/
CustomerData::CustomerData(string f, string l, string st, string cit, string adr, string ph, string zp, int num, bool ml): PersonData(f, l, st, cit, adr, ph, zp){
    customerNumber = num;
    mailingList = ml;
}

/*
Description: Returns the customerNumber of the object
Parameters: 
            None
Return: 
            (int) customerNumber: Unique customer number
Notes:
*/
int CustomerData::getCustomerNumber(){
    return customerNumber;
}

/*
Description: Returns whether or not the customer is a part of the mailing list
Parameters: 
            None
Return: 
            (bool) mailingList: Whether or not the person signed up for the mailing list
Notes: 
*/
bool CustomerData::getMailingList(){
    return mailingList;
}

/*
Description: Sets the unique number of the customer
Parameters: 
            (int) cn: New number to be assigned
Return:
            None
Notes: 
*/
void CustomerData::setCustomerNumber(int cn){
    customerNumber = cn;
}

/*
Description: Sets whether or not the person is signed up for the mailing list
Parameters: 
            (bool) ml: New mailing list status;
Return: 
            None
Notes: 
*/
void CustomerData::setMailingList(bool ml){
    mailingList = ml;
}

/*
Description: Returns a string of the customers data
Parameters: 
            None
Return: 
            (string) record: Formated string of the customers recorded info
Notes: 
*/
string CustomerData::getRecord(){
    // Get the info that is shared with the parent class
    string begin = PersonData::getRecord();
    string ml = "";
    if(mailingList) ml = "Yes";
    else ml = "No";
    return begin + " / " + "C#: " + to_string(customerNumber) + " / " + "ML: " + ml;     
}

/*
Description: Prints out the customers record in a list
Parameters: 
            None
Return: 
            None
Notes: 
*/
void CustomerData::PrintRecord(){
    // Call the parent class function first so you print out the overlap
    PersonData::PrintRecord();
    cout << "Customer Number: " << to_string(customerNumber) << endl;

    string ml = "";
    if(mailingList) ml = "Yes";
    else ml = "No";
    
    cout << "On Mailing List: " << ml << endl;
}
