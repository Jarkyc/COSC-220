#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    int size, cSize = 0;
    int max = 1;
    int *array;
    int *count;
    char yn;
    bool dsp;
    srand(time(0));
    
    // ====== Beginning of program (prompts) ====== 
    cout << "Enter in the size of the array: ";
    cin >> size;
    
    if(size <= 0){
        array = nullptr;
        count = nullptr;
        return 1;
    }
    
    cout << "Input the upper bound for a range of random numbers for the array: ";
    cin >> max;
    
    if(max <= 0){
        array = nullptr;
        count = nullptr;
        return 1;
    }
    
    cout << "Do you want a print out of the array? (y/n): ";
    cin >> yn;
    
    if(yn =='y' || yn == 'y') dsp = true;
    else dsp = false;
    
    
    // ====== Array Population ====== 
    array = new int[size];
    
    for(int i = 0; i < size; i++){
        int rnd = (rand() % max) + 1;
        array[i] = rnd;
        if(dsp) cout << array[i] << " ";    // Display as you populate if marked yes (bracket style)
    }
    
    cout << endl;
    
    // ====== Display if marked yes (dereference style) ====== 
    int offset = 0;
    while(dsp){
     cout << *(array + offset) << " ";
     offset++;
     
     if(offset >= size) dsp = false;
    }
    
    cout << endl;
    
    // ====== Populate Count ====== 
    
     cSize = max;   //Array has the possibility of having 1 of each number, 1-max. We assume it does for 
                    //max memory reasons
    
    
    count = new int[cSize];
    
    // Start by populating everything as 0
    for(int i = 0; i < cSize; i++){
        count[i] = 0;
    }
    
    // Populate Count
    for(int i = 0; i < size; i++){
        int val = array[i]; 
        int num = count[val - 1]; 
        count[val - 1] = num+1;
    }
    
    cout << "Counts: " << endl;
    for(int i = 0; i < cSize; i++){
        int val = count[i];
        cout << i + 1 << ": " << val << endl;
    }
    
    
    // ====== Clear Everything ====== 
    delete[] array;
    array = nullptr;
    
    delete[] count;
    count = nullptr;
    
    return 0;
    

}
