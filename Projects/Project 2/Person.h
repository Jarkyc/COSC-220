// TODO - COMMENT
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "FeetInches.h"
#include "Date.h"

using namespace std;

class Person {

protected:
    string first;
    string last;
    FeetInches height;
    double weight;
    Date dob;
public:
    Person();
    Person(string, string, FeetInches, double, Date);
    string formalName();
    string infName();
    FeetInches getHeight();
    double getWeight();
    Date getDOB();
    virtual string toString();
};

#endif
