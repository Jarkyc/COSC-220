/*
Author: Charles Reigle
Creation Date: 4/12/23
Last Update: 4/13/23
Description: Main program implementing NBAPlayer and NFLPlayer. Loads in data sheets and properly populates array with the correct data types pertaining to the sport
User Interface: None
Notes:
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "Date.h"
#include "FeetInches.h"
#include "Person.h"
#include "NBAPlayer.h"
#include "NFLPlayer.h"

using namespace std;

void loadNBADataFile(string, vector<Person*>&);
void loadNFLDataFile(string, vector<Person*>&);
void printList(vector<Person*>);
void sortName(vector<Person*>&);
void sortHeight(vector<Person*>&);
void sortWeight(vector<Person*>&);

int main(){

    vector<Person*> PlayerInfo;

    loadNBADataFile("NBA.csv", PlayerInfo);
    loadNFLDataFile("NFL.csv", PlayerInfo);

    cout << "Number of players in files: " << PlayerInfo.size() << endl;
    cout << endl;

    cout << "Player List" << endl;
    for(Person *p : PlayerInfo){
        cout << p->toString() << endl;;
    }

    // Sort by name
    cout << endl;
    cout << "Sorted Player List" << endl;
    sortName(PlayerInfo);
    printList(PlayerInfo);

    // Tall players
    vector<Person*> TallPlayers;
    FeetInches seven;
    seven.setFeet(7);
    for(Person *p: PlayerInfo){
        if(p->getHeight() > seven || p->getHeight() == seven) TallPlayers.push_back(p);
    }
    sortHeight(TallPlayers);
    cout << endl;
    cout << "Tall Player List" << endl;
    printList(TallPlayers);
    cout << endl;
    cout << "Number of players over 6 feet, 11 inches = " << TallPlayers.size() << endl;

    // People >= 350 pounds. Sort
    vector<Person*> BigPlayers;
    for(Person *p : PlayerInfo){
        if(p->getWeight() > 350) BigPlayers.push_back(p);
    }
    sortWeight(BigPlayers);
    cout << endl;
    cout << "Big Player List" << endl;
    printList(BigPlayers);
    cout << endl;
    cout << "Number of Players over 350lbs. = " << BigPlayers.size() << endl;

    // Tallest Players
    cout << endl;
    vector<Person*> TallestPlayers;
    // We can minimize the time by using a list of players we already know are really tall
    Person *tallest = TallPlayers[0];
    for(Person *p : TallPlayers){
        if(p->getHeight() > tallest->getHeight()) tallest = p;
    }

    for(Person *p : TallPlayers){
        if(p->getHeight() == tallest->getHeight()) TallestPlayers.push_back(p);
    }
    sortName(TallestPlayers);
    cout << "Tallest Players List" << endl;
    printList(TallestPlayers);


    // Oldest player. Sort by name if there are people of the same height
    cout << endl;
    vector<Person*> OldestPlayers;
    Person *oldest = PlayerInfo[0];
    for(Person *p : PlayerInfo){
        Date date = p->getDOB();
        // Disregard empty dates
        if(date.toString() == "-1/-1/-1") continue;
        if(p->getDOB() < oldest->getDOB()) oldest = p;
    }

    // We know from the example there is only one oldest person in the files, however if you want to use another file where maybe there are 2 people born on the same day, we want to check that
    for(Person *p : PlayerInfo){
        if(p->getDOB() == oldest->getDOB()) OldestPlayers.push_back(p);
    }
    sortName(OldestPlayers);
    cout << "Oldest Players List" << endl;
    printList(OldestPlayers);

    // Youngest Player. Sort by name if there are people of the same height
    cout << endl;
    vector<Person*> YoungestPlayers;
    Person *youngest = PlayerInfo[0];
    for(Person *p : PlayerInfo){
        Date date = p->getDOB();
        // Disregard empty dates
        if(date.toString() == "-1/-1/-1") continue;
        if(p->getDOB() > youngest->getDOB()) youngest = p;
    }

    for(Person *p : PlayerInfo){
        if(p->getDOB() == youngest->getDOB()) YoungestPlayers.push_back(p);
    }
    sortName(YoungestPlayers);
    cout << "Youngest Players List" << endl;
    printList(YoungestPlayers);

    // We only need to delete the universal list because all the lists and pointer variables share the same pointers
    for(Person *p : PlayerInfo){
        delete p;
    }
    return 0;
}

/*
Description: Loads in the data file for NBA Players and populates the ector
Parameters:
            (string) name: name of the file
            (vector<Person*>) &list: List to  insert the data objects into
Return:
            None
Notes:
*/
void loadNBADataFile(string name, vector<Person*> &list){
    ifstream file;
    file.open("data/" + name);

    string details;

    //Skip the header line
    getline(file, details);

    while(getline(file, details)){
        stringstream s(details);

        string last;
        string first;
        string jersey;
        string pos;
        string height;
        string weight;
        string dob;

        getline(s, last, ',');
        getline(s, first, ',');
        getline(s, jersey, ',');
        getline(s, pos, ',');
        getline(s, height, ',');
        getline(s, weight, ',');
        getline(s, dob);

        // There is a chance the information wont be filled in. Prevents conversion of empty strings
        int jersNum;
        if(jersey == "") jersNum = -1;
        else jersNum = stoi(jersey);

        double dubWeight;
        if(weight == "") dubWeight = 0;
        else dubWeight = stod(weight);

        Date d;
        if(dob != "") d.setMDY(dob);

        FeetInches f;
        if(height != "") f.setLength(height);

        NBAPlayer *p = new NBAPlayer(last, first, f, dubWeight, d, pos, jersNum);
        list.push_back(p);
    }
    file.close();
}

/*
Description: Loads the NFL Players data file and populates the vector
Parameters:
            (string) name: name of the file
            (vector<Person*>) &list: List to  insert the data objects into
Return:
            None
Notes:
*/
void loadNFLDataFile(string name, vector<Person*> &list){
    ifstream file;
    file.open("data/" + name);

    string details;

    //Skip the header line
    getline(file, details);

    while(getline(file, details)){
        stringstream s(details);

        string strNum;
        string first;
        string last;
        string pos;
        string height;
        string weight;
        string dob;
        string team;

        getline(s, strNum, ',');
        getline(s, last, ',');
        getline(s, first, ',');
        getline(s, pos, ',');
        getline(s, height, ',');
        getline(s, weight, ',');
        getline(s, dob, ',');
        getline(s, team);

        // Get rid of the quotation marks
        last.erase(last.begin());
        first.erase((first.begin() + first.length()) - 1);

        // Get rid of the space at the beginning of the first name
        first.erase(first.begin());


        // There is a chance the information wont be filled in. Prevents conversion of empty strings
        int jersNum;
        if(strNum == "") jersNum = -1;
        else jersNum = stoi(strNum);

        double dubWeight;
        if(weight == "") dubWeight = -1;
        else dubWeight = stod(weight);

        Date d;
        if(dob != "") d.setMDY(dob);

        FeetInches f;
        if(height != "") f.setInches(stoi(height));

        NFLPlayer *player = new NFLPlayer(last, first, f, dubWeight, d, jersNum, pos, team);
        list.push_back(player);

    }
    file.close();
}

/*
Description: Prints out tehe vector that is sent to it
Parameters:
            (vector<Person*>) arr: vector to print
Return:
            None
Notes:
*/
void printList(vector<Person*> arr){
    for(Person *p : arr){
        cout << p->toString() << endl;
    }
}

/*
Description: Sorts the vector based on the name of the players, in alphebetical order
Parameters:
            (vector<Person*>) &array: Array to sort
Return:
            None
Notes:
*/
void sortName(vector<Person*> &array) {
    int size = array.size();
    for (int itemsSorted = 1; itemsSorted < size; itemsSorted++) {
        Person* temp = array[itemsSorted];
        int loc = itemsSorted - 1;
        while (loc >= 0 && array[loc]->formalName().compare(temp->formalName()) > 0) {
            array[loc + 1] = array[loc];
            loc = loc - 1;
        }
        array[loc + 1] = temp;
    }
}


/*
Description: Sorts the vector height of the players, with tallest first
Parameters:
            (vector<Person*>) &array: Array to sort
Return:
            None
Notes:
*/
void sortHeight(vector<Person*> &array){
    int size = array.size();
    for (int itemsSorted = 1; itemsSorted < size; itemsSorted++) {
        Person* temp = array[itemsSorted];
        int loc = itemsSorted - 1;
        while (loc >= 0 && array[loc]->getHeight() < temp->getHeight()) {
            array[loc + 1] = array[loc];
            loc = loc - 1;
        }
        array[loc + 1] = temp;
    }
}


/*
Description: Sorts the vector based on the weight of the players, with largest at the top
Parameters:
            (vector<Person*>) &array: Array to sort
Return:
            None
Notes:
*/
void sortWeight(vector<Person*> &array){
    int size = array.size();
    for (int itemsSorted = 1; itemsSorted < size; itemsSorted++) {
        Person* temp = array[itemsSorted];
        int loc = itemsSorted - 1;
        while (loc >= 0 && array[loc]->getWeight() < temp->getWeight()) {
            array[loc + 1] = array[loc];
            loc = loc - 1;
        }
        array[loc + 1] = temp;
    }
}

