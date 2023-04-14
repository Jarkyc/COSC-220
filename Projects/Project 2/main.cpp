// TODO - comment

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

    // Max height. Sort by name if there are people of the same height

    // Oldest player. Sort by name if there are people of the same height

    // Youngest Player. Sort by name if there are people of the same height

    // clear all memory!!!!!!!!!!!!!!!
    return 0;
}

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

void printList(vector<Person*> arr){
    for(Person *p : arr){
        cout << p->toString() << endl;
    }
}

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
