/*
Author: Charles Reigle
Creation Date: 3/31/23
Last Update: 3/31/23
Description: Dice roll simulation that displays equal rolls
User Interface: Number of trials, number of dice per trial, whether or not to display the rolls
Notes:
*/
#include "Die.h"
#include "Array2D.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));
    int trials = 0;
    int dice = 0;
    int sim = 0;
    bool dsp = false;
    string ans;

    // User input
    cout << "Input the number of trials: ";
    cin >> trials;

    cout << "Input the number of dice for each trial: ";
    cin >> dice;

    do {
        cout << "Do you want to display the array (Y/N): ";
        cin >> ans;
    } while (ans != "y" && ans!= "n" && ans != "Y" && ans != "N");


    // Set display
    if(ans == "y" || ans == "Y") dsp = true;
    else dsp = false;

    // Create array
    Die d(6);
    Array2D<Die> A(trials, dice, d);

    //Populate array
    for(int i = 0; i < trials; i++){
        for(int k = 0; k < dice; k++){
            (A[i][k]).roll();
            if(dsp){
                cout << A[i][k] << " ";
            }
        }
        if(dsp) cout << endl;
    }

    // Calculate equalities
    for(int i = 0; i < trials; i++){
        bool dp = true;
        Die curr = A[i][0];
        for(int k = 0; k < dice; k++){
            if(A[i][k] != curr) dp = false;
        }
        if(dp) sim++;
    }

    cout << "There were " << sim << " matches of equal die in the " << trials << " trials of the simulation" << endl;

}
