/**
Author: Charles Reigle
Creation Date: 3/1/23
Last Update: 3/1/23
Description: Dice rolls stored in a 2D array
User Interface: None
Notes: 
**/ 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array2D.h"
#include "Die.h"

bool isDuplicates(int*, int);

using namespace std;

int main() {
    srand(time(0));

    int rolls, trials;
    Array2D Simulation;
    Die d1, d2;

    cout << "Input the number of trials: ";
    cin >> trials;

    cout << "Input the number of dice rolls per trial: ";
    cin >> rolls;

    Simulation.resize(trials, rolls);

    // Conduct all the rolls and put them in the simulation
    for(int t = 0; t < trials; t++){
        for(int r = 0; r < rolls; r++){
            int val = 0;
            d1.roll();
            val += d1.getValue();
            d2.roll();
            val += d2.getValue();
            Simulation.set(t, r, val);
        }
    }

    Simulation.display(4);

    int amnt = 0;
    int size = Simulation.getCols();
    int* arr = new int[size];
    for(int i = 0; i < Simulation.getRows(); i++){
        for(int k = 0; k < size; k++){
            arr[k] = Simulation.get(i, k);
        }
        if(isDuplicates(arr, size)) amnt++;
    }

    cout << "Number of trials resulting in the same roll value was " << amnt << "." << endl;
    
    return 0;
}

bool isDuplicates(int* arr, int size){
    int curr = arr[0];
    int temp;
    for(int i = 1; i < size; i++){
        temp = arr[i];
        if(temp != curr) return false;
    }
    return true;
}
