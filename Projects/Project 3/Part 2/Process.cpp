/*
Author: Charles Reigle
Creation Date: 4/27/23
Last Update: 4/27/23
Description: Implementation of the Process class, representing a process in the CPU to test timings
Notes:
*/

#include "Process.h"

using namespace std;

/*
Description: Constructor for the Process. Time is defaultly set to 1, and time stamp is defaultly set to 0 in the header.
Parameters:
            (int) time: Execution time of the process
            (int) stamp: Time stamp of when the process is created
Return:
Notes:
*/
Process::Process(int time, int stamp){
    exeTime = time;
    timeStamp = stamp;
}

/*
Description: Copy constructor of the Process.
Parameters:
            const (Process) &obj: Object to copy the values from
Return:
Notes:
*/
Process::Process(const Process &obj){
    exeTime = obj.exeTime;
    timeStamp = obj.timeStamp;
}

/*
Description: Deconstructor of the Process. Does nothing, there is no data to clear
Parameters:
Return:
Notes:
*/
Process::~Process(){
}

/*
Description: Sets the execution time of the process
Parameters:
            (int) t: New execution time to set
Return:
Notes:
*/
void Process::setExeTime(int t){
    if(t < 1) return;

    exeTime = t;
}

/*
Description: Gets the execution time of the process
Parameters:
Return:
        (int) exeTime: Amount of cycles it will take to execute the process
Notes:
*/
int Process::getExeTime(){
    return exeTime;
}

/*
Description: Sets the time stamp (cycle) of when the process was created
Parameters:
            (int) t: New timestamp
Return:
Notes:
*/
void Process::setTimeStamp(int t){
    timeStamp = t;
}

/*
Description: Returns the timestamp (cycle) the process was created on
Parameters:
Return:
            (int) timeStamp: Cycle the process was created on
Notes:
*/
int Process::getTimeStamp(){
    return timeStamp;
}

/*
Description: Overloaded assignment operator
Parameters:
            const (Process) &right: Object to copy the data over from
Return:
            (Process): This process
Notes:
*/
const Process Process::operator =(const Process &right){
    exeTime = right.exeTime;
    timeStamp = right.timeStamp;

    return *this;
}

/*
Description: Overloaded stream operator. Prints out [exeTime, timeStamp]
Parameters:
            (ostream) &strm: The stream to insert into
            const (Process) &p: Object to Print out
Return:
            (ostream) &strm: The stream inserted into
Notes:
*/
ostream &operator << (ostream &strm, const Process &p){
    strm << "[" << p.exeTime << ", " << p.timeStamp << "]";
    return strm;
}

