// TODO - COMMENT

#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack<string> stk;      // Stack of delims
    string input;           // Input string
    string ch;              // Character at cur pos of string
    string pop;             // Most recent input in stk
    bool balanced = true;   // Whether or not the string is balanced

    cout << "Enter Expression: ";
    getline(cin, input);

    for(int i = 0; i < input.length(); i++){
        ch = input[i];
        // If it an opening bracket. push it into the stack
        if(ch == "{" || ch == "(" || ch == "[") stk.push(ch);

        // Are the delimiters closing values of the most recently input character?
        if(ch == "}"){
            pop = stk.top();
            if(pop != "{"){
                balanced = false;
                break;
            }
            stk.pop();
        } else if(ch == ")"){
            pop = stk.top();
            if(pop != "("){
                balanced = false;
                break;
            }
            stk.pop();
        } else if(ch == "]"){
            pop = stk.top();
            if(pop != "["){
                balanced = false;
                break;
            }
            stk.pop();
        }
    }

    if(balanced) cout << "Delimiters are balanced" << endl;
    else cout << "Delimiters are not balanced" << endl;



    return 0;
}
