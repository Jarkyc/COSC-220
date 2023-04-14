/*
Author: Charles Reigle
Creation Date: 4/12/24
Last Update: 4/12/24
Description: Specifications of the NBAPlayer class, child class of Person. Stores information on jersey number and the position of the player.
Notes:
*/
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
