/**
Author: Charles Reigle
Creation Date: 2/24/2023
Last Update: 2/24/2023
Description: Takes in a csv file pertaining to carbon emission data and breaks it into states. The data for every year of the state is then processed and stored. User is then prompted to select a state and a year, and then the data for the year is displated.
User Interface: Data file to select. Must be contained in the data/ folder
Notes:
**/

#include "StateData.h"
#include <sstream>
#include <string>

using namespace std;

void addYear(string, string*&, int&);
void printYears(string*, int);
void printStates(StateData*, int);
int yearIndex(string, string*, int);
StateData getState(int n);

int main(){
    ifstream file;
    string input, currState, data;
    string name = "data/";
    int line = 0, position = 0, yearsAmnt = 0, statesAmnt = 0;
    int answer;

    string* yearsList = new string[0];


    cout << "Enter in the name of the file you wish to access: ";
    cin >> input;

    name += input;

    file.open(name);
    if(!file.good()){
        cout << "File does not exist. Exiting program." << endl;
        return 0;
    }

    //Get the amount of states (lines in the file)
    string details;
    while(getline(file, details)){
        statesAmnt++;
    }
    // Account for header
    statesAmnt--;

    // Reset cursor pos
    file.clear();
    file.seekg(0L, ios::beg);

    // Create list of state data
    StateData* stateData = new StateData[statesAmnt];

    // Populate stateData
    for(int i = 0; i < statesAmnt; i++){
        StateData state;
        stateData[i] = state;
    }


    // For every line
    while(getline(file, details)){
        stringstream ss(details);

        // For every element in the line
        while(getline(ss, data, ',')){
            // Ignore the "State" part of the header. Get all the years
            if(line == 0 && position != 0){
                addYear(data, yearsList, yearsAmnt);
                // If it is a state
            } else if(line != 0){

                // State name is position 0
                if(position == 0){
                    stateData[line - 1].setStateName(data);

                    // Data is every position after
                } else {
                    stateData[line - 1].add(stod(data));
                }
            }
            // Increase the position
            position++;
        }

        // Reset position because we are on a new line
        position = 0;

        // Go to the new line
        line++;
    }

    // Prompt for selecting a state
    do {
        cout << "Select a state" << endl;
        printStates(stateData, statesAmnt);
        cin >> answer;
    } while((answer <= 0) || (answer > statesAmnt));

    // Account for lists indexes starting at 0 (1 less than the numbers displayed)
    answer--;

    // Set the state that was selected
    StateData* selectedState = &stateData[answer];

    // Prompt for selecting a year
    int index;
    do{
        cout << "Select a year" << endl;
        printYears(yearsList, yearsAmnt);
        cin >> answer;
        index = yearIndex(to_string(answer), yearsList, yearsAmnt);
    }while(index == -1);

    cout << "The energy-related carbon dioxide emissions for " << (*selectedState).getStateName() << " in millions of metric tons in the year " << answer << " was "  << (*selectedState).get(index) << "." << endl;


    file.close();

    // Release all the data
    selectedState = nullptr;

    delete[] stateData;
    stateData = nullptr;

    delete[] yearsList;
    yearsList = nullptr;

    return 0;
}

/**
Description: Adds a year to the years list and updates the size
Parameters:
            (string) year: year to add to list
            (string *&) yearsList: list to be added to
            (int &) size: size of list
Return:
            None
Notes:
**/
void addYear(string year, string *&yearsList, int &size){
    string *newList = new string[size + 1];
    for(int i = 0; i < size; i++){
        newList[i] = yearsList[i];
    }
    newList[size] = year;

    delete[] yearsList;
    yearsList = newList;
    newList = nullptr;
    size++;
}

/**
Description: Prints all the years in the list
Parameters:
            (string *) years: years list
            (int) size: size of list
Return:
            None
Notes:
**/
void printYears(string *years, int size){
    for(int i = 0; i < size; i++){
        cout << years[i] << endl;
    }
}

/**
Description: Prints all the states names in the StateData list
Parameters:
            (StateData *) stateData: states data list
            (int) size: size of list
Return:
Notes:
**/
void printStates(StateData *stateData, int size){
    for(int i = 0; i < size; i++){
        cout << i + 1 << ". " << stateData[i].getStateName() << endl;
    }
}

/**
Description: Returns the index of the input year
Parameters:
            (string) year: year to find
            (string *) years: years list
            (int) size: size of list
Return:
            (int) index: index of the year in the list. -1 if not found.
Notes:
**/
int yearIndex(string year, string* years, int size){
    for(int i = 0; i < size; i++){
        if (years[i] == year) return i;
    }
    return -1;
}


