/*
Author: Charles Reigle
Creation Date: 5/3/23
Last Update: 5/3/23
Description: A program testing the time of different sorting algorthms
User Interface: Which sorting algorithm does the user want to test and how many items do they want to test
Notes:
*/
#include <iostream>
#include "BinaryTree.h"
#include <chrono>
#include <ctime>
#include <iostream>

using namespace std;
using namespace std::chrono;

template <class T> void merge(T A[], T Temp[], int startA, int startB, int end);
template <class T> void mergeSort(T A[], T Temp[], int start, int end);
template <class T> void mergeSort(T A[], int size);
template <class T> void quickSort(T A[], int left, int right);
template <class T> void quickSort(T A[], int size);

int main(){
    int sortMethod = 0;
    cout << "Select Sorting Algorithm: 1. Merge Sort   2. Quick Sort   3. "
            "Tree Sort: ";
    cin >> sortMethod;

    int size = 0;
    cout << "Input Array Size: ";
    cin >> size;

    int *A = new int[size];
    BinaryTree<int> tree;
    srand(time(0));

    for (int i = 0; i < size; i++)
        A[i] = rand();

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    if (sortMethod == 1)
        mergeSort(A, size);
    else if (sortMethod == 2)
        quickSort(A, size);
    else
        tree.treeSort(A, size);

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    cout << "Execution Time: " << time_span.count() << " seconds." << endl;

    delete[] A;
    return 0;
}

// Sorting Algorithms

template <class T>
void merge(T A[], T Temp[], int startA, int startB, int end) {
    int aptr = startA;
    int bptr = startB;
    int i = startA;

    while (aptr < startB && bptr <= end)
        if (A[aptr] < A[bptr])
            Temp[i++] = A[aptr++];
        else
            Temp[i++] = A[bptr++];

    while (aptr < startB)
        Temp[i++] = A[aptr++];

    while (bptr <= end)
        Temp[i++] = A[bptr++];

    for (i = startA; i <= end; i++)
        A[i] = Temp[i];
}

template <class T> void mergeSort(T A[], T Temp[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(A, Temp, start, mid);
        mergeSort(A, Temp, mid + 1, end);
        merge(A, Temp, start, mid + 1, end);
    }
}

template <class T> void mergeSort(T A[], int size) {
    T *Temp = new T[size];
    mergeSort(A, Temp, 0, size - 1);
    delete[] Temp;
}

///////////////////////////////////////////////////////////

template <class T> void quickSort(T A[], int left, int right) {
    int i = left;
    int j = right;
    int mid = (left + right) / 2;

    T pivot = A[mid];

    while (i <= j) {
        while (A[i] < pivot)
            i++;

        while (A[j] > pivot)
            j--;

        if (i <= j) {
            T tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(A, left, j);

    if (i < right)
        quickSort(A, i, right);
}

template <class T> void quickSort(T A[], int size) {
    quickSort(A, 0, size - 1);
}
