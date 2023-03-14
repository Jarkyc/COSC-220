#include <iostream>
#include <fstream>
#include <sstream>
#include "Date.h"
#include "StockDay.h"
#include "StockList.h"

using namespace std;

string PATH = "data/";

int main(){

    string fileName = "";
    StockList obj;
    ifstream file;

    cout << "File to load: ";
    cin >> fileName;

    PATH += fileName;

    file.open(PATH);
    if(!file.good()){
        cout << "File does not exist. Exiting program." << endl;
        return 0;
    }


    string details, data;

    // Skip the header line
    getline(file, details);

    while(getline(file, details)){
        stringstream ss(details);

        // Process every stockday in here.
        while(getline(ss, data, ',')){
            cout << data << endl;
        }
        cout << "-------------------------------" << endl;
    }
    /*
    Date date1(3, 14, 2023);
    StockDay sd(date1, 0.0, 0.0, 0.0, 0.0, 0.0, 0);
    StockDay sd1(date1, 1.0, 0.0, 0.0, 0.0, 0.0, 0);
    StockDay sd2(date1, 1.0, 2.0, 0.0, 0.0, 0.0, 0);
    StockList sl;

    sl.append(sd);
    sl.append(sd1);
    sl.append(sd2);

    cout << sl << endl;
    */

    return 0;
}
