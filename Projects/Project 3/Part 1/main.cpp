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
Notes:
*/
#include <iostream>
#include "PriorityQueue.h"
#include "Process.h"

using namespace std;

Process createProcess(int, int, int);
int randomPrio(int);

int main(){
    srand(time(0));

    int idleTime, executed, totalWait;      //How long the cpu has beein idling, how many Processes have been executed, The total wait time of all the process ran
    int cores, min, max, levels, length;    //Number of cores to simulate, Min exe time, max exe time, max priority level, the number of cycles to run
    double ppc;                             //The number of new Process to create per cycle
    double newProcess = 0;                  //The progress of the new Process created every cycle
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
    cout << "Input the Number of New Process per Cycle: ";
    cin >> ppc;
    cout << "Input the Length of the Simulation in Cycles: ";
    cin >> length;

    // Create the simulated CPU, and seed it with Processes.
    int *cpu = new int[cores];              //CPU cores to simulate
    for(int i = 0; i < cores; i++){
        Process p = createProcess(max, min, 0);
        cpu[i] = p.getExeTime();
        executed++;
    }

    // Simulation Loop
    for(int i = 0; i < length; i++){
        int idleAmnt = 0;                   //How many cores were idling on the cycle
        // Process every core
        for(int c = 0; c < cores; c++){
            // If the core is empty
            if(cpu[c] == 0){

                // Increase the idle time if there are no process
                if(q.isEmpty()){
                    idleAmnt++;

                // If there are processes waiting, fill the cores
                }else{
                    Process newP = q.dequeue();
                    cpu[c] = newP.getExeTime();
                    executed++;
                    totalWait += i - newP.getTimeStamp();
                }
            } else {
                // Execute the process
                cpu[c] = cpu[c] - 1;
            }

        }
        // Implement the idle time
        idleTime += idleAmnt;

        // Implement the new processes
        newProcess += ppc;
        while(newProcess >= 1){
            Process newP = createProcess(max, min, i);
            q.enqueue(newP, rand () % levels + 1);

            newProcess -= 1;
        }
    }

    int totalExeTime = 0;                   //The execution time of all the Processes still waiting to be ran
    int maxWait = 0                         //Max wait time out of all the processes still in queue
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


    cout << endl;
    cout << "============ Simulation Results ============" << endl;
    cout << "Idle Time = " << idleTime << endl;
    cout << "Processes Completed = " << executed << endl;
    cout << "Total Wait Time of Completed Processess = " << totalWait << endl;
    cout << "Number of Processes Remaining in Queue = " << q.size() << endl;
    cout << "Total Execution Time Needed for Unprocessed Processes = " << totalExeTime << endl;
    cout << "Total Wait Time for Unprocessed Processes = " << queuedWait << endl;
    cout << "Maximum Wait Time for Unprocessed Processes = " << maxWait << endl;
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
