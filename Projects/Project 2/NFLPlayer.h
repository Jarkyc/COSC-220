#ifndef NFLPLAYER_H
#define NFLPLAYER_H

#include <iostream>
#include "Person.h"
#include "Date.h"
#include "FeetInches.h"

using namespace std;

class NFLPlayer : public Person{
private:
    string teamCode;
    string position;
    int number;

public:
    NFLPlayer();
    NFLPlayer(string, string, FeetInches, double, Date, int, string, string);
    string positionCode();
    int getNumber();
    string getTeamCode();
    string toString();

};

#endif
