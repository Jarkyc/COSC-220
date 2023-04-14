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

/*
Description: Default constructor for the NFLPlayer. Sets all member variables to default values
Parameters:
            None
Return:
            None
Notes:
*/
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

/*
Description: Constructor for NFLPlayer taking in parameters
Parameters:
            (string) l: Last Name
            (string) f: First Name
            (FeetInches) ft: Height
            (double) w: Weight
            (Date) d: Date of Birth
            (int) n: Jersey Number
            (string) p: Position Code
            (string) tc: Team Codes
Return:
            None
Notes:
*/
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

/*
Description: Returns the position code of the player
Parameters:
            None
Return:
            (string) position: Position Code
Notes:
*/
string NFLPlayer::positionCode(){
    return position;
}

/*
Description: Returns the jersey number of the player
Parameters:
            None
Return:
            (int) number: Jersey Number
Notes:
*/
int NFLPlayer::getNumber(){
    return number;
}

/*
Description: Returns the team code of the player
Parameters:
            None
Return:
            (string) teamCode: TeamCode
Notes:
*/
string NFLPlayer::getTeamCode(){
    return teamCode;
}

/*
Description: Returns a formated string of the players information
Parameters:
            None
Return:
            (string): Formated information
Notes:
*/
string NFLPlayer::toString(){
    string pd = Person::toString();

    return pd + " / " + position + " / " + to_string(number) + " / " + getTeamCode() + " / NFL";
}
