#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    int rolls, dice, cSize = 0;
    int *sums;
    int *count;
    char answer;
    bool prt; 
    srand(time(0));
    
    cout << "Enter in the number of rolls: ";
    cin >> rolls;
    
    if(rolls <= 0){
        sums = nullptr;
        count = nullptr;
        return 1;
    }
    
    cout << "Enter in the number of dice: ";
    cin >> dice;
    
    if(dice <= 0){
        sums = nullptr;
        count = nullptr;
        return 1;
    }
    
    cout << "Do you want to print the array (y/n): "; 
    cin >> answer;
    
    if(answer == 'y' || answer == 'Y') prt = true;
    else prt = false;
    
    sums = new int[rolls];
    
    for(int r = 0; r < rolls; r++){
        int sum = 0;
        for(int d = 0; d < dice; d++){
            int diceVal = (rand() % 6) + 1;
            sum += diceVal;
        }
        sums[r] = sum;
        
        if(prt) cout << sums[r] << " ";
    }
    
    cout << endl;
    
    // The max val is 6 * dice
    // The min val is 1 * dice
    
    int offset = dice;
    cSize = (6 * dice) - offset + 1; 
    count = new int[cSize];
    
    for(int i = 0; i < cSize; i++){
        count[i] = 0;
    }
    
    for(int i = 0; i < rolls; i++){
        int sum = sums[i];
        int val = count[sum - offset];
        count[sum - offset] = val + 1;
    }
    
    cout << "Counts: " << endl;
    for(int i = 0; i < cSize; i++){
        cout << i + offset << ": " << count[i] << endl;
    }
    
    
    
    
    cout << endl;
    
    delete[] sums;
    sums = nullptr;
    
    delete[] count;
    count = nullptr;
    
}
