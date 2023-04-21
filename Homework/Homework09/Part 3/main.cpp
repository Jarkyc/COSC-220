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
bool placeQueens(vector<int> &queenList, int col, int &its) {
	int row;
	bool foundLocation;

	if (col == 8){	// stopping condition
		for(int i = 0; i < 8; i++)
			cout << queenList[i] << " ";
		cout << endl;
		its++;
	}else {
		row = 0;

		while (row < 8) {
			if (safeLocation(row, col, queenList)) {
				queenList[col] = row;
				foundLocation = placeQueens(queenList, col + 1, its);
				if (!foundLocation){
					row++;
				}
			} else
				row++;
		}
	}

	// pass success or failure back to previous col
	return foundLocation;
}

int main() {

	for(int i = 0; i < 8; i++){
		int its = 0;
		cout << "Position " << i  << ": " << endl;
		vector<int> queenList(8);
		queenList[0] = i;
		placeQueens(queenList, 1, its);
		cout << "The number of solutions is " << its << endl;
		cout << endl;
	}



	return 0;
}
