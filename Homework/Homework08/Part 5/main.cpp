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

    for(int i : permList){
        cout << i << endl;
    }

}

void permute(vector<int> permList, int index){

}
