/**
Author: Charles Reigle
Creation Date: 2/24/2023
Last Update: 2/24/2023
Description: Implementation of the StateData class
Notes:
**/
#include "StateData.h"

using namespace std;

/**
Description: Constructor allocates all data needed for the class like the data list, the size variable, and the name variable.
Parameters:
            None
Return:
            None
Notes:
**/
StateData::StateData(){
    StateName = "";
    size = 0;
    data = nullptr;
}

/**
Description: Deconstructor deallocates all data and frees up memory
Parameters:
            None
Return:
            None
Notes:
**/
StateData::~StateData(){
    delete[] data;
    data = nullptr;
}

/**
Description: Sets the name of the state
Parameters:
            (string) n: name to be set
Return:
            None
Notes:
**/
void StateData::setStateName(string n){
    StateName = n;
}

/**
Description: Gets the name of the state
Parameters:
            None
Return:
            (string) name: name of the state
Notes:
**/
string StateData::getStateName(){
    return StateName;
}

/**
Description: Adds a value to the data list
Parameters:
            (double) x: Data to be added
Return:
            None
Notes:
**/
void StateData::add(double x){
    double* newData = new double[size + 1];

    for(int i = 0; i < size; i++){
        newData[i] = data[i];
    }
    newData[size] = x;

    delete[] data;
    data = newData;
    newData = nullptr;

    size++;

}

/**
Description: Gets the value in the data list at the input index
Parameters:
            (int) n: index
Return:
            (double) value: value at the index
Notes:
**/
double StateData::get(int n){
    if(size == 0) return 0;
    if(n < 0) n = 0;
    if(n > size - 1) n = size -1;

    return data[n];
}
