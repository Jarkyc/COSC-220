/*
Author: Charles Reigle
Creation Date: 4/27/23
Last Update: 4/27/23
Description: Program that simulates a cpu, with processes and priorities.
User Interface:
            - Number of cpu cores to simulate
            - Minimum execution time for a Process
            - Maximum execution time for a Process
            - Max priority of a process
            - Number of new processes to be created per cycle
            - How many cyles to run
Notes: I couldn't get the data to import when the output values were separated by tabs, so I separated them by commas in order to import them
*/
#include <iostream>
#include "PriorityQueue.h"
#include "Process.h"

using namespace std;

Process createProcess(int, int, int);
int randomPrio(int);

int main(){
    srand(time(0));

    int cores, min, max, levels, length;    //Number of cores to simulate, Min exe time, max exe time, max priority level, the number of cycles to run
    double ppc;                             //The number of new Process to create per cycle
    double minProc = 0, maxProc = 0;        //Process Increments to start at, Process Increments to end at
    PriorityQueue<Process> q;               //Queue of processes to be ran

    // Gather all the user data
    cout << "Input the Number of CPU Cores: ";
    cin >> cores;
    cout << "Input the Minimum Number of Execution Cylces per Process: ";
    cin >> min;
    cout << "Input the Maximum Number of Execution Cycles per Process: ";
    cin >> max;
    cout << "Input the Number of Priority Levels: ";
    cin >> levels;
    cout << "Minimum Number of New Processes Per Cycle: ";
    cin >> minProc;
    cout << "Maximum Number of New Processes Per Cycle: ";
    cin >> maxProc;
    cout << "New Processes per Cycle Step Size: ";
    cin >> ppc;
    cout << "Input the Length of the Simulation in Cycles: ";
    cin >> length;


    cout << endl;
    cout << "============ Simulation Results ============" << endl;
    cout << "Load Idle Completed Processed Wait Unprocessed Exe. Needed Unprocessed Wait Unprocessed Max. Wait" << endl;

    //For every process cycle type
    for(double r = minProc; r <= maxProc; r += ppc){
        int idleTime = 0, executed = 0, totalWait = 0;      //How long the cpu has beein idling, how many Processes have been executed, The total wait time of all the process ran
        double newProcess = 0;                  //The progress of the new Process created every cycle

        // Create the simulated CPU, and seed it with Processes.
        int *cpu = new int[cores];              //CPU cores to simulate
        for(int i = 0; i < cores; i++){
            Process p = createProcess(max, min, 0);
            cpu[i] = p.getExeTime();
            executed++;
        }

        // Simulation Loop
        for(int i = 0; i < length; i++){
            // Process every core
            for(int c = 0; c < cores; c++){
                // If the core is empty
                if(cpu[c] <= 0){

                    // Increase the idle time if there are no process
                    if(q.isEmpty()){
                        idleTime++;

                    // If there are processes waiting, fill the cores
                    }else{
                        Process newP = q.dequeue();
                        cpu[c] = newP.getExeTime();
                        executed++;
                        totalWait += i - newP.getTimeStamp();
                    }
                }
                // Execute the process
                cpu[c] = cpu[c] - 1;

            }


            // Implement the new processes
            newProcess += r;
            while(newProcess >= 1){
                Process newP = createProcess(max, min, i);
                q.enqueue(newP, rand () % levels + 1);

                newProcess -= 1;
            }
        }

        int totalExeTime = 0;                   //The execution time of all the Processes still waiting to be ran
        int maxWait = 0 ;                        //Max wait time out of all the processes still in queue
        unsigned long queuedWait = 0;           //Total wait time of all the Processes still in queue

        // If there Processes never ran, gather all their data
        if(!q.isEmpty()){
            maxWait = length - q[0].data.getTimeStamp();
            for(int i = 0; i < q.size(); i++){
                totalExeTime += q[i].data.getExeTime();

                int currWait = length - q[i].data.getTimeStamp();   //Wait time of the current Process waiting in queue
                if(currWait > maxWait) maxWait = currWait;

                queuedWait += (length - q[i].data.getTimeStamp());
            }
        }

        cout << r << "," << idleTime << "," << executed << "," << totalWait << "," << q.size() << "," << totalExeTime << "," << queuedWait << "," << maxWait  << "," << endl;

        q.clear();
        delete[] cpu;
    }

    return 0;
}

/*
Description: Creates a new process with a random execution time between the parameters the user specifies
Parameters:
            (int) max: Max execution time
            (int) min: Min execution time
            (int) cycle: Cycle the process was created on
Return:
            (Process): New process
Notes:
*/
Process createProcess(int max, int min, int cycle){
    int r = rand() % (max-min + 1) + min;               // Random exe time between the min and the max input

    Process p(r, cycle);

    return p;
}
