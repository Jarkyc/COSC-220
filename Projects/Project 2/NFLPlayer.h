/*
Author: Charles Reigle
Creation Date: 4/12/23
Last Update: 4/12/23
Description: Specifications of the NFLPlayer class, child class of Person. Stores information like jersey number, position code, and team code
Notes:
*/

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
