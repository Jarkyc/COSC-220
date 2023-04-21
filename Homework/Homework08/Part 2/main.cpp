/*
Author: Charles Reigle
Creation Date: 4/17/23
Last Update: 4/17/23
Description: Postfix calculator using the custom Stack and Queue classes
User Interface: Postfix expression to evaluate
Notes:
*/

#include "Queue.h"
#include "Stack.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main() {

    // string input = "234 32 + 7 *";
    // Must have spaces between tokens.

    string input;
    cout << "Enter a postfix expression: ";
    getline(cin, input);

    Stack<string> calc; //Calculated numbers
    Queue<string> tokens;   // Characters in the expression
    stringstream inputstream(input);
    string token;



    // Tokenizing w.r.t. space ’ ’
    while (getline(inputstream, token, ' ')){
        if(token != " ")tokens.enqueue(token);
    }
    // Printing the token queue for testing.
    try {
        while (!tokens.isEmpty()){
            string val = tokens.dequeue();
            // For each of the supported evaluations, it pops 2 of the numbers from the front of the calc stack and evaluates and reinserts them
            if(val == "+"){
                double val2 = stod(calc.pop());
                double val1 = stod(calc.pop());

                double answer = val1 + val2;
                calc.push(to_string(answer));
            } else if(val == "-"){
                double val2 = stod(calc.pop());
                double val1 = stod(calc.pop());

                double answer = val1 - val2;
                calc.push(to_string(answer));
            } else if(val == "*"){
                double val2 = stod(calc.pop());
                double val1 = stod(calc.pop());

                double answer = val1 * val2;
                calc.push(to_string(answer));
            } else if(val =="/"){
                double val2 = stod(calc.pop());
                double val1 = stod(calc.pop());

                double answer = val1 / val2;
                calc.push(to_string(answer));
            } else{
                calc.push(val);
            }
        }
    } catch (string s) {
        cout << s << endl;
    }

    cout << "Value: " << calc.pop() << endl;
}
