#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct StateData{
 string Name;
 double* data;

};

int main(){
    ifstream file;
    string input, name, details, element;
    int stateSize = 0;
    int yearsSize = 50;
    int* years = new int[50];


    cout << "Enter in the file name: ";
    cin >> input;

    name = "data/" + input;

    file.open(name);

    while(getline(file, details)){
        stateSize++;
    }
    file.clear();
    file.seekg(0L, ios::beg);

    for(int i = 0; i < stateSize; i++){
        getline(file, details);
        stringstream ss(details);
        for(int j = 0; j < yearsSize + 1; j++){
            getline(ss, element, ',');
            if(i == 0){
                if(j == 0){
                    continue;
                }
                years[j - 1] = stoi(element);
            } else {
                StateData state;
                if(j == 0){
                    state.Name = element;
                    cout << state.Name << endl;
                }
            }

        }
    }

    cout << endl;
    for(int i = 0; i < 50; i++){
        cout << years[i] << endl;
    }


}
