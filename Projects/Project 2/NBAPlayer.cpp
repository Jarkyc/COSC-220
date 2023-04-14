/*
Author: Charles Reigle
Creation Date: 4/12/23
Last Update: 4/12/23
Description: Implementation of the NBAPlayer class
Notes:
*/
#include <iostream>
#include "NBAPlayer.h"
#include "Date.h"
#include "FeetInches.h"
#include "Person.h"

/*
Description: Default constructor. Sets member variables to default values
Parameters:
            None
Return:
            None
Notes:
*/
NBAPlayer::NBAPlayer(){
    last = "";
    first = "";
    FeetInches ft;
    height = ft;
    weight = 0.0;
    Date d;
    dob = d;
    code = "";
    number = -1;
}

/*
Description: Constructor using parameters
Parameters:
            (string) l: Last Name
            (string) f: First Name
            (FeetInches) ft: Height
            (double) w: Weight
            (Date) d: Date of Birth
            (string) c: Position code
            (int) num: Jersey Number
Return:
            None
Notes:
*/
NBAPlayer::NBAPlayer(string l, string f, FeetInches ft, double w, Date d, string c, int num): Person(l, f, ft, w, d){
    code = c;
    number = num;
}

/*
Description: Returns the position code of the player
Parameters:
            None
Return:
            (string) code: Position code
Notes:
*/
string NBAPlayer::positionCode(){
    return code;
}

/*
Description: Returns the jersey number of the player
Parameters:
            None
Return:
            (int) number: Jersey Number
Notes:
*/
int NBAPlayer::getNumber(){
    return number;
}

/*
Description: Returns a formated string of the players information
Parameters:
            None
Return:
            (string): Formatted information
Notes:
*/
string NBAPlayer::toString(){
    string pd = Person::toString();

    return pd + " / " + code + " / " + to_string(number) + " / NBA";
}
