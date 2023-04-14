/*
Author: Charles Reigle
Creation Date: 4/12/23
Last Update: 4/12/23
Description: Implementation of the NFLPLayer class
Notes:
*/

#include <iostream>
#include "NFLPlayer.h"
#include "Person.h"
#include "Date.h"
#include "FeetInches.h"

using namespace std;

NFLPlayer::NFLPlayer(){
    last = "";
    first = "";
    FeetInches ft;
    height = ft;
    weight = 0.0;
    Date d;
    dob = d;
    position = "";
    number = -1;
    teamCode = "";
}

NFLPlayer::NFLPlayer(string l, string f, FeetInches ft, double w, Date d, int n, string p, string tc){
    last = l;
    first = f;
    height = ft;
    weight = w;
    dob =d;
    number = n;
    position = p;
    teamCode = tc;
}

string NFLPlayer::positionCode(){
    return position;
}

int NFLPlayer::getNumber(){
    return number;
}

string NFLPlayer::getTeamCode(){
    return teamCode;
}

string NFLPlayer::toString(){
    string pd = Person::toString();

    return pd + " / " + position + " / " + to_string(number) + " / " + getTeamCode() + " / NFL";
}
