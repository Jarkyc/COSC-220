/**
Author: Charles Reigle
Creation Date:
Last Update:
Description:
User Interface: <List of all user options and short descriptions of each option>
Notes: <Any notes that a user of the program should know about>
**/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void div();
int* duplicateArray(int*, int);
void display(int*, int);
int* getRandomNumbers(int);
void sort(int*, int);
bool sorted(int*, int);
void concat(int*, int, int*, int);
void remove(int*, int, int, int);
void shuffle(int*, int);
void sub(int*, int, int, int);
void insert(int*, int, int*, int, int);
void resize(int*, int, int);


int main(){
    srand(time(0));

    div();

    int* arr = getRandomNumbers(10);
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }

    div();

    int* arr2 = duplicateArray(arr, 10);

    for(int i = 0; i < 10; i++){
        cout << arr2[i] << " ";
    }

    div();

    return 0;
}

void div(){
    cout << endl;
    cout << "--------------------------------------" << endl;
}

int* getRandomNumbers(int size){
    int* arr = new int[size];

    for(int i = 0; i < size; i++){
        arr[i] = rand();
    }

    return arr;

}

int* duplicateArray(int *arr, int size){
    int* arr2 = new int[size];

    for(int i = 0; i < size; i++){
        arr2[i] = arr[i];
    }

    return arr2;

}
