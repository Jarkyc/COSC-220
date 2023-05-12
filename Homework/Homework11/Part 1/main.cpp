#include <iostream>
#include "BinaryTree.h"
#include "AVLTree.h"
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int binarySearch(int [], int, int, int);

int main(){
    srand(time(0));

    BinaryTree<int> binaryTree;
    AVLTree<int> ATree;
    int size = 1000000, searches = 0;
    double Bt = 0, At = 0, aa = 0;

    //cout << "Enter number of integers to use: ";
    //cin >> size;
    cout << "Enter number of searches to use: ";
    cin >> searches;

    int *arr = new int[size];

    //Populate array
    for(int i = 0; i < size; i++){
        arr[i] = rand()%(1000000000) + 1;
    }

    cout << endl;

    //---------------------------
    // INSERTIONS
    //---------------------------

    // Time for BT insertion
    auto start = high_resolution_clock::now();
    for(int i = 0; i < size; i++){
        binaryTree.insertNode(arr[i]);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time to insert into Binary Tree: " << duration.count() / 1000000.0 << " seconds" << endl;
    Bt += duration.count() / 1000000.0;

    // Time for AVL insertion
    start = high_resolution_clock::now();
    for(int i = 0; i < size; i++){
        ATree.insertNode(arr[i]);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to insert into Binary Tree: " << duration.count() / 1000000.0 << " seconds" << endl;
    At += duration.count() / 1000000.0;

    // Time for algorithm sort
    start = high_resolution_clock::now();
    sort(arr, arr + size);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to sort array (algorithm library method): " << duration.count() / 1000000.0 << " seconds" << endl;
    aa += duration.count() / 1000000.0;

    cout << endl;

    //---------------------------
    // SEARCHES
    //---------------------------

    // Time BT Search
    start = high_resolution_clock::now();
    for(int i = 0; i < searches; i++){
        binaryTree.searchNode(rand()%(1000000000) + 1);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to search Binary Tree: " << duration.count() / 1000000.0 << " seconds" << endl;
    Bt += duration.count() / 1000000.0;

    // Time AVL Search
    start = high_resolution_clock::now();
    for(int i = 0; i < searches; i++){
        ATree.searchNode(rand()%(1000000000) + 1);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to search AVL Tree: " << duration.count() / 1000000.0 << " seconds" << endl;
    At += duration.count() / 1000000.0;

    // Time array binary Search
    start = high_resolution_clock::now();
    for(int i = 0; i < searches; i++){
        binarySearch(arr, 0, size-1, rand()%(1000000000) + 1);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to search array: " << duration.count() / 1000000.0 << " seconds" << endl;
    aa += duration.count() / 1000000.0;

    cout << endl;

    //---------------------------
    // TOTAL TIMES
    //---------------------------

    cout << "Total Time in Seconds" << endl;
    cout << "Binary Tree: " << Bt << endl;
    cout << "AVL Tree: " << At << endl;
    cout << "Array: " << aa << endl;

    delete [] arr;

    return 0;
}

int binarySearch(int array[], int first, int last, int value)
{
   int middle; // Mid point of search

   if (first > last)
      return -1;
   middle = (first + last)/2;
   if (array[middle]==value)
      return middle;
   if (array[middle]<value)
      return binarySearch(array, middle+1,last,value);
   else
      return binarySearch(array, first,middle-1,value);
}
