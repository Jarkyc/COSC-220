/*
Author: Charles Reigle
Creation Date: 4/12/23
Last Update: 4/12/23
Description: Implementation of the Person class
Notes:
*/
#include "Person.h"

using namespace std;

Person::Person(){
    first = "";
    last = "";
    FeetInches f;
    height = f;
    weight = 0.0;
    Date d;
    dob = d;
}

Person::Person(string l, string f, FeetInches ht, double w, Date d){
    last = l;
    first = f;
    height = ht;
    weight = w;
    dob = d;
}

string Person::formalName(){
    return last + ", " + first;
}

string Person::infName(){
    return first + " " + last;
}

FeetInches Person::getHeight(){
    return height;
}

double Person::getWeight(){
    return weight;
}

Date Person::getDOB(){
    return dob;
}

string Person::toString(){
    return formalName() + " / " + height.toString() + " / " + to_string(weight) + " / " + dob.toString();
}
