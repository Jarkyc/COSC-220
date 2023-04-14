/*
Author: Charles Reigle
Creation Date: 4/12/23
Last Update: 4/12/23
Description: Implementation of the Person class
Notes:
*/
#include "Person.h"

using namespace std;

/*
Description: Default constructor that assigns default values to member variables
Parameters:
            None
Return:
            None
Notes:
*/
Person::Person(){
    first = "";
    last = "";
    FeetInches f;
    height = f;
    weight = 0.0;
    Date d;
    dob = d;
}

/*
Description: Constructor that takes in parameters
Parameters:
            (string) l: Last Name
            (string) f: First Name
            (FeetInches) ht: Height
            (double) w: Weight
            (Date) d: Date of Birth
Return:
            None
Notes:
*/
Person::Person(string l, string f, FeetInches ht, double w, Date d){
    last = l;
    first = f;
    height = ht;
    weight = w;
    dob = d;
}

/*
Description: Returns the formal Last, First name conventions
Parameters:
            None
Return:
            (string): Last, First
Notes:
*/
string Person::formalName(){
    return last + ", " + first;
}

/*
Description: Returns informal First Last name conventions
Parameters:
            None
Return:
            (string): First Last
Notes:
*/
string Person::infName(){
    return first + " " + last;
}

/*
Description: Returns the FeetInches object of the persons height
Parameters:
            None
Return:
            (FeetInches) height: Persons height
Notes:
*/
FeetInches Person::getHeight(){
    return height;
}

/*
Description: Returns a double of the persons weight
Parameters:
            None
Return:
            (double) weight: Weight
Notes:
*/
double Person::getWeight(){
    return weight;
}

/*
Description: Returns the date object of the persons date of birth
Parameters:
            None
Return:
            (Date) dob: Date of Birth
Notes:
*/
Date Person::getDOB(){
    return dob;
}

/*
Description: Returns a formatted string of the persons information
Parameters:
            None
Return:
            (string): Formatted information string
Notes:
*/
string Person::toString(){
    return formalName() + " / " + height.toString() + " / " + to_string(weight) + " / " + dob.toString();
}
