#ifndef NBAPLAYER_H
#define NBAPLAYER_H

#include <iostream>
#include "Person.h"
#include "Date.h"
#include "FeetInches.h"

using namespace std;

class NBAPlayer : public Person{

private:
    string code;
    int number;

public:
    NBAPlayer();
    NBAPlayer(string, string, FeetInches, double, Date, string, int);
    string positionCode();
    int getNumber();
    string toString();

};

#endif
