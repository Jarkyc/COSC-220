/*
Author: Charles Reigle
Creation Date: 4/21/23
Last Update: 4/21/23
Description: Calculates the permutations of the integer list 1 - n
User Interface: n number of intgers
Notes:
*/

#include <iostream>
#include <vector>

using namespace std;

void permute(vector<int>, int);

int main(){

    int size;
    vector<int> permList;

    cout << "Enter the size of the permutation list: ";
    cin >> size;

    for(int i = 1; i <= size; i++){
        permList.push_back(i);
    }

    permute(permList, 0);
    cout << GLOBAL << endl;

}

void permute(vector<int> permList, int index) {

    // Stopping condition
    if (index == permList.size()-1) {
        for (int i = 0; i < permList.size(); i++)
            cout << permList[i] << " ";
        cout << endl;
    } else {
        permute(permList, index+1); // Permute the base list
        for (int j = index+1; j < permList.size(); j++) {  // Permute through all the other numbers
            swap(permList[index], permList[j]);
            permute(permList, index+1);
        }
    }
}
