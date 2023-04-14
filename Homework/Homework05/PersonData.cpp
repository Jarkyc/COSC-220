/*
Author: Charles Reigle
Creation Date: 3/9/23
Last Update: 3/9/23
Description: Implementation of the PersonData class
Notes: 
*/

#include "PersonData.h"

using namespace std;

/*
Description: PersonData constructor
Parameters:
            (string) f: First Name
            (string) l: Last Name
            (string) st: State
            (string) cit: City
            (string) adr: Address
            (string) ph: Phone Number
            (string) zp: Zip Code
Return:
            None
Notes:
*/
PersonData::PersonData(string f, string l, string st, string cit, string adr, string ph, string zp){
    firstName = f;
    lastName = l;
    state = st;
    city = cit;
    address = adr;
    phone = ph;
    zip = zp;
}

/*
Description: Gets the last name of the person
Parameters: 
            None
Return: 
            (string) lastName: last name
Notes:
*/
string PersonData::getLastName(){
    return lastName;
}

/*
Description: Gets the first name of the person
Parameters: 
            None
Return: 
            (string) firstName: first name
Notes:
*/
string PersonData::getFirstName(){
    return firstName;
}

/*
Description: Gets the state of the person
Parameters: 
            None
Return: 
            (string) state: state
Notes:
*/
string PersonData::getState(){
    return state;
}

/*
Description: Gets the city of the person
Parameters: 
            None
Return: 
            (string) city: city
Notes:
*/
string PersonData::getCity(){
    return city;
}

/*
Description: Gets the address of the person
Parameters: 
            None
Return: 
            (string) address: address
Notes:
*/
string PersonData::getAddress(){
    return address;
}

/*
Description: Gets the phone number of the person
Parameters: 
            None
Return: 
            (string) phone: phone number
Notes:
*/
string PersonData::getPhone(){
    return phone;
}

/*
Description: Gets the zip code of the person
Parameters: 
            None
Return: 
            (string) zip: zip code
Notes:
*/
string PersonData::getZip(){
    return zip;
}

/*
Description: Sets the name of the person
Parameters: 
            (string) first: first name
            (string) last: last name
Return: 
            None
Notes:
*/
void PersonData::setName(string first, string last){
    firstName = first;
    lastName = last;
}

/*
Description: Sets the address of the person
Parameters: 
            (string) street: street
            (string) c: city
            (string) s: state
            (string) z: zip code
Return: 
            None
Notes:
*/
void PersonData::setAddress(string street, string c, string s, string z){
    address = street;
    city = c;
    state = s;
    zip = z;
}

/*
Description: Sets the phone number of the person
Parameters: 
            (string) p: new phone number
Return: 
            None
Notes:
*/
void PersonData::setPhone(string p){
    phone = p;
}

/*
Description: Sets the zip code of the person
Parameters: 
            (string) z: zip code
Return: 
            None
Notes:
*/
void PersonData::setZip(string z){
    zip = z;
}

/*
Description: Gets the record data of the person as one string
Parameters: 
            None
Return: 
            (string) record: formated record data
Notes:
*/
string PersonData::getRecord(){
    return firstName + " " + lastName + " / " + address + " / " + city + ", " + state + " " + zip + " / " + phone;  
}

/*
Description: Prints out the record data of the person in a list
Parameters: 
            None
Return: 
            None
Notes:
*/
void PersonData::PrintRecord(){
    cout << lastName << ", " << firstName << endl;
    cout << address << endl;
    cout << city << ", " << state << " " << zip << endl;
    cout << phone << endl;
}
