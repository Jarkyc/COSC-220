/*
====================================================================
Author: Charles Reigle
Creation Date: 2/1/23
Last Update: 2/1/23
Description: Example code of pointers with comments.
User Interface:
Notes:
====================================================================
*/
#include <iostream>

using namespace std;

void div();         // Creates a prototype of a function to be declared later

int main(){
    int x = 25;

    cout << "The address of x is " << &x << endl;
    cout << "The size of x is " << sizeof(x) << endl;
    cout << "The size of the pointer to x is " << sizeof(&x) << " bytes" << endl;
    cout << "The value in x is " << x << endl;

    div();

    int *ptr = nullptr;

    ptr = &x;       // Pointer Variables store the location
    cout << "The value in x is " << x << endl;
    cout << "The value in x is " << *ptr << endl;     // Gets the actual value that is at a memory address
    cout << "The address of x is " << ptr << endl;

    div();

    int numbers[] = {20, 5, 3, 15, 23, 42, 56};     // The variable assigned to an array is actually a pointer to the first item in an array
    cout << "The first element of the array is: ";
    cout << *numbers << endl;       // We can dereference the array to get values out of it because it is a pointer
    cout << "Proof: " << numbers[0] << endl;
    cout << *(numbers + 3) << endl;     // Another example. By adding 3 to the pointer, it shifts over 3 memory locations, and then we are dereferencing it with * to get the value
    cout << "Proof: " << numbers[3] << endl;
}

void div(){
    cout << "================================================" << endl;
}
