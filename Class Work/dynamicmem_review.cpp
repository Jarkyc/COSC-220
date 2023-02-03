/*
====================================================================
Author: Charles Reigle
Creation Date: 2/3/23
Last Update: 2/3/23
Description: Example code of dynamic memory with comments.
User Interface:
Notes:
====================================================================
*/
#include <iostream>

using namespace std;

int main(){
    double *arr = nullptr;  // Defines a new empty memory location for a pointer to a double
    int size = 0;   // Just defines a new size var defaulted to 0.

    cout << "Input the size of the array: ";
    cin >> size;

    if(size <= 0){
        return 1;
    }

    arr = new double[size]; // New creates something new in a memory location (dynamic memory).
                            // New returns a memory address.

    for(int count = 0; count < size; count++){
        cout << "Enter number " << (count + 1) << ": ";
        cin >> arr[count];
    }

    double sum = 0;
    for(int count = 0; count < size; count++){
     sum += arr[count];
    }

    cout << "Sum = " << sum << endl;

    delete[] arr;   // Deletes the __DATA__ and deallocates the memory of the __DATA__. Need to include [] to let it know to delete the whole array
    arr = nullptr;  // Deallocates the __POINTER__ value. If you dont allocate it null, you will get garbge if you happen to reference it later
                    // However nullptr is the 0th position in memory, and you cannot get to it. It will seg fault if you try and access it unchecked

                    //If Valgrind is installed, you can run "valgrind ./a.out" and it will run the program and then show you memory statistics at the end of the program

}
