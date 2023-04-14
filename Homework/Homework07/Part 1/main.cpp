/*
Author: Charles Reigle
Creation Date: 3/30/23
Last Update: 3/30/23
Description: Timing test between linked lists and vectors
User Interface: Amount of items the user wants to test
Notes:
*/

/*
12) Buble sort is always the wrost sort, and then comes the linked list, selection short, and finally insertion sort is the quickest every time. Just like the linked, list, the bubble sort timing goes up exponentially each time.
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

template<class T>
void bubbleSort(T*, int);

template<class T>
void selectionSort(T*, int);

template<class T>
void insertionSort(T*, int);

int main(){
    srand(time(0));

    int runs;
    
    cout << "How many items do you wish to store: ";
    cin >> runs;

    LinkedList<int> linkedList;
    vector<int> vec;
    
    // take out of scientific notation it is defaulting to 
    cout << fixed;

    for(int i = 0; i < runs; i++){
        int random = rand()%(0 - 20000 + 1);
        vec.push_back(random);
    }
    
    // Linked list clock
    auto start = high_resolution_clock::now();
    for(int i = 0; i < runs; i++){
        linkedList.insertNode(vec.at(i));
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time to sort with linked list: " << duration.count() / 1000000.0 << " seconds" << endl;

    int *arr = new int[vec.size()];
     // array bubble clock
    start = high_resolution_clock::now();
    for(int i = 0; i < vec.size(); i++){
        arr[i] = vec.at(i);
    }
    bubbleSort(arr, runs);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to sort array with bubble sort: " << duration.count() / 1000000.0 << " seconds" << endl;

     // array insertion clock
    start = high_resolution_clock::now();
    for(int i = 0; i < vec.size(); i++){
        arr[i] = vec.at(i);
    }
    insertionSort(arr, runs);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to sort array with insertion sort: " << duration.count() / 1000000.0 << " seconds" << endl;

     // array selection clock
    start = high_resolution_clock::now();
    for(int i = 0; i < vec.size(); i++){
        arr[i] = vec.at(i);
    }
    selectionSort(arr, runs);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to sort array with selection sort: " << duration.count() / 1000000.0 << " seconds" << endl;

    delete [] arr;

    return 0;
}

template<class T>
void bubbleSort(T* array, int size) {
    int maxElement;
    int index;
    for (maxElement = size - 1; maxElement > 0; maxElement--){
        for (index = 0; index < maxElement; index++){
            if (array[index] > array[index + 1]){
                swap(array[index], array[index + 1]);
            }
        }
    }
}

template<class T>
void selectionSort(T* array, int size) {
    int minIndex, minValue;
        for (int start = 0; start < (size - 1); start++) {
            minIndex = start;
            minValue = array[start];
            for (int index = start + 1; index < size; index++) {
                if (array[index] < minValue) {
                    minValue = array[index];
                    minIndex = index;
                }
            }
        swap(array[minIndex], array[start]);
    }
}

template<class T>
void insertionSort(T* array, int size) {
    for (int itemsSorted = 1; itemsSorted < size; itemsSorted++) {
        int temp = array[itemsSorted];
        int loc = itemsSorted - 1;
        while (loc >= 0 && array[loc] > temp) {
            array[loc + 1] = array[loc];
            loc = loc - 1;
        }
        array[loc + 1] = temp;
    }
}


