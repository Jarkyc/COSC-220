/*
Author: Charles Reigle
Creation Date: 4/27/23
Last Update: 4/27/23
Description: Specification of the Proccess class
Notes:
*/
#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <math.h>

using namespace std;

class Process{
private:
    int exeTime;        // How many cycles it will take for the process to execute
    int timeStamp;      // The cycle the process was created on

public:
    Process(int time = 1, int stamp = 0);
    Process(const Process &obj);
    ~Process();

    void setExeTime(int);
    int getExeTime();
    void setTimeStamp(int);
    int getTimeStamp();

    const Process operator= (const Process &right);
    friend ostream &operator << (ostream&, const Process&);

};

#endif
