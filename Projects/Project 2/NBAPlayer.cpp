//TODO - Comment

#include <iostream>
#include "NBAPlayer.h"
#include "Date.h"
#include "FeetInches.h"
#include "Person.h"

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

NBAPlayer::NBAPlayer(string l, string f, FeetInches ft, double w, Date d, string c, int num): Person(l, f, ft, w, d){
    code = c;
    number = num;
}

string NBAPlayer::positionCode(){
    return code;
}

int NBAPlayer::getNumber(){
    return number;
}

string NBAPlayer::toString(){
    string pd = Person::toString();

    return pd + " / " + code + " / " + to_string(number) + " / NBA";
}
