#include <iostream>

using namespace std;

double add(double x, double y) { return x + y; }
double sub(double x, double y) { return x - y; }
double mul(double x, double y) { return x * y; }
double div(double x, double y) { return x / y; }
double run(double x, double y, double (*fctptr)(double, double)) { return fctptr(x, y); }   // Runs the input function and returns its data value

typedef double (*fcttype)(double, double);

int main(){
    double (*fctptr)(double, double);   // Almost like a prototype. Creates a function that is a pointer to any function, that takes in 2 double params and a double output
    fctptr = add;
    cout << fctptr(3, 7) << endl;

    cout << endl;

    //double (*fcttype[3])(double, double); // You can make an array of the functions by defining it as such
    fcttype fcttype[4] = {add, sub, mul, div}; // Or, you can make an array via typedef

    for(int i = 0; i < 4; i++){
        cout << fcttype[i](3, 7) << endl;
    }

    cout << endl;

    // You can pass a function pointer to a function as a parameter. God is dead and we have killed him
    for(int i = 0; i < 4; i++){
        cout << run(3, 7, fcttype[i]) << endl;
    }
}
