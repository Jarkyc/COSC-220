//============================================================================
// Name        : ConstructorDestructor.cpp
// Author      : Don Spickler
// Version     : 1.1
// Description : Constructor Syntax Example #2 for Chapter 13 on Objects
// Note        : This program demonstrates a destructor.
//               This is a combination of examples from the text with some
//               minor changes.  
//============================================================================

#include <iostream>

using namespace std;

class Demo {
  public:
    Demo();     // Constructor
    ~Demo();    // Destructor
};

Demo::Demo() {
    cout << "Welcome to the constructor!\n";
}

Demo::~Demo() {
    cout << "The destructor is now running.\n";
}

int main() {
    Demo demoObject;

    cout << "This program demonstrates an object\n";
    cout << "with a constructor and destructor.\n";
    return 0;
}
