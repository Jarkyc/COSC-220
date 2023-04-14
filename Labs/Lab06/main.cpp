/*
Author: Charles Reigle
Creation Date: 3/30/23
Last Update: 3/30/23
Description: Timing test between linked lists and vectors
User Interface: Amount of items the user wants to test
Notes:
*/

/*
3) The timing for the linkedlist is increasting exponentially, and it takes far longer to insert into the linked list than it does the vector. 

6)When doing 100000 insertions, 4,999,850,001 next assignments were done
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include "LinkedList.h"

using namespace std;
using namespace std::chrono;


int main(){
    srand(time(0));

    // Initialize all variables
    int runs;
    LinkedList<int> linkedList;
    vector<int> vec;
    
    cout << "How many items do you wish to store: ";
    cin >> runs;
    
    // seed random
    int random = rand();
    
    // take out of scientific notation it is defaulting to 
    cout << fixed;
    
    // Linked list clock
    auto start = high_resolution_clock::now();
    for(int i = 0; i < runs; i++){
        linkedList.appendNode(random);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time to append with linked list: " << duration.count() / 1000000.0 << " seconds" << endl;
    cout << linkedList.counter << endl;

    // Vector clock
    start = high_resolution_clock::now();
    for(int i = 0; i < runs; i++){
        vec.push_back(random);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to append with vector: " << duration.count() / 1000000.0 << " seconds" << endl;
    
    
    return 0;
}
