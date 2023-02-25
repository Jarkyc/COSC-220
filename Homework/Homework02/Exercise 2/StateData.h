/**
Author: Charles Reigle
Creation Date: 2/24/2023
Last Update: 2/24/2023
Description: Layout for the StateData class
Notes:
**/

#ifndef STATEDATA_H
#define STATEDATA_H

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class StateData{

private:
    string StateName;
    double* data;
    int size;

public:
    StateData();
    ~StateData();

    void setStateName(string);
    string getStateName();
    void add(double);
    double get(int);

};

#endif
