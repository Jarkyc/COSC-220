//============================================================================
// Name        : Constructor.cpp
// Author      : Don Spickler
// Version     : 1.1
// Description : Constructor Syntax Example #1 for Chapter 13 on Objects
// Note        : This program demonstrates a constructor.
//               This is a combination of examples from the text with some
//               minor changes.  
//============================================================================

#include <iostream>

using namespace std;

class Demo {
  public:
    Demo();     // Constructor
};

Demo::Demo() {
    cout << "Welcome to the constructor!\n";
}

int main() {
    Demo demoObject;

    cout << "This program demonstrates an object\n";
    cout << "with a constructor.\n";
    return 0;
}
