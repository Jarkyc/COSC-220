<<<<<<< HEAD
/*
Author: Charles Reigle
Creation Date: 4/17/23
Last Update: 4/17/23
Description: Postfix calculator using c++ STL stacks and queues
User Interface: Postfix expression to evaluate
Notes:
*/


#include <stack>
#include <queue>
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

    stack<string> calc; // Calculated numbers
    queue<string> tokens;   // Characters in the expression
    stringstream inputstream(input);
    string token;



    // Tokenizing w.r.t. space ’ ’
    while (getline(inputstream, token, ' ')){
        if(token != " ")tokens.push(token);
    }
    // Printing the token queue for testing.
    try {
        while (!tokens.empty()){
            string val = tokens.front();
            tokens.pop();
            // For each of the supported evaluations, it pops 2 of the numbers from the front of the calc stack and evaluates and reinserts them
            if(val == "+"){
                double val2 = stod(calc.top());
                calc.pop();
                double val1 = stod(calc.top());
                calc.pop();

                double answer = val1 + val2;
                calc.push(to_string(answer));
            } else if(val == "-"){
                double val2 = stod(calc.top());
                calc.pop();
                double val1 = stod(calc.top());
                calc.pop();

                double answer = val1 - val2;
                calc.push(to_string(answer));
            } else if(val == "*"){
                double val2 = stod(calc.top());
                calc.pop();
                double val1 = stod(calc.top());
                calc.pop();

                double answer = val1 * val2;
                calc.push(to_string(answer));
            } else if(val =="/"){
                double val2 = stod(calc.top());
                calc.pop();
                double val1 = stod(calc.top());
                calc.pop();

                double answer = val1 / val2;
                calc.push(to_string(answer));
            } else{
                calc.push(val);
            }
        }
    } catch (string s) {
        cout << s << endl;
    }

    cout << "Value: " << calc.top() << endl;
=======
// The program solves the 8-Queens problem. it prompts the user for
// the starting row for the queen in column 0 and calls the recursive
// backtracking function queens() to determine if there is a solution.
// if there is a solution, the position of the queens is passed to
// the chessboard object, board, and a call to its drawBoard() function
// shows the placement of the queens.
// This is an update from the textbook of Ford and Topp.

#include <iostream>
#include <vector>


using namespace std;

// Can a queen at (row,col) be attacked by any of the
// non-attacking queens in columns 0 to col-1 ?
bool safeLocation(int row, int col, const vector<int> &queenList) {
	for (int qCol = 0; qCol < col; qCol++) {
		int qRow = queenList[qCol];
		if (qRow == row)
			return false;
		else if (qCol == col)
			return false;
		else if (qCol - qRow == col - row || qCol + qRow == col + row)
			return false;
	}
	return true;
}

// Place a queen in columns col through 7
bool placeQueens(vector<int> &queenList, int col) {
	int row;
	bool foundLocation;

	if (col == 8)	// stopping condition
		foundLocation = true;
	else {
		foundLocation = false;
		row = 0;

		while (row < 8 && !foundLocation) {
			if (safeLocation(row, col, queenList)) {
				queenList[col] = row;
				foundLocation = placeQueens(queenList, col + 1);
				if (!foundLocation)
					row++;
			} else
				row++;
		}
	}

	// pass success or failure back to previous col
	return foundLocation;
}

int main() {
	int row;
	vector<int> queenList(8);

	cout << "Enter row for queen in column 0: ";
	cin >> row;
	cout << endl;

	queenList[0] = row;

	if (placeQueens(queenList, 1)) {
		for (unsigned int i = 0; i < queenList.size(); i++)
			cout << queenList[i] << " ";

		cout << endl << endl;

	} else
		cout << "No solution" << endl;

	return 0;
>>>>>>> master
}
