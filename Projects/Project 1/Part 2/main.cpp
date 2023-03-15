/*
Author: Charles Reigle
Creation Date: 3/13/2023
Last Update: 3/15/2023
Description: Simulates stock trading between 2 companies stocks
User Interface:
                Name of File1 to open
                Name of File2 to open
                Initial investment of company 1
                Intiial investment of compant 2
                Percent to move on each transaction
Notes:
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include "Date.h"
#include "StockDay.h"
#include "StockList.h"

using namespace std;

void loadDataFile(ifstream&, StockList&);
void daily(double, double, StockList, StockList, double);
void multiDays(double, double, StockList, StockList, double, int);
bool isDown(StockDay);
bool isUp(StockDay);
bool isDown(StockDay, StockDay);
bool isUp(StockDay, StockDay);

string PATH = "data/";
ifstream file1;
ifstream file2;

int main(){

    StockList one;
    StockList two;

    double initOne, initTwo, per;

    string file1Path = PATH;
    string file2Path = PATH;
    string input;
    cout << fixed;
    cout << "Company 1 File: ";
    cin >> input;
    file1Path += input;

    file1.open(file1Path);
    if(!file1.good()){
        cout << "File does not exist. Exiting program." << endl;
        return 0;
    }

    loadDataFile(file1, one);

    cout << "Company 2 File: ";
    cin >> input;
    file2Path += input;

    file2.open(file2Path);
    if(!file2.good()){
        cout << "File does not exist. Exiting program." << endl;
        return 0;
    }

    loadDataFile(file2, two);

    // PROCESS DATES
    int amount;

    // Take the starting date of both
    // Set the global starting date to the latest
    Date startOne = (*one[0]).getDate();
    Date startTwo = (*two[0]).getDate();
    Date globalStart;
    if(startOne > startTwo) globalStart = startOne;
    else globalStart = startTwo;

    // Take the ending date of both
    // Set the global ending date to the earliest
    Date endOne = (*one[one.getSize() - 1]).getDate();
    Date endTwo = (*two[two.getSize() - 1]).getDate();
    Date globalEnd;
    if(endOne < endTwo) globalEnd = endOne;
    else globalEnd = endTwo;

    cout << "Simulation Date Range: " << globalStart << " to " << globalEnd << endl;

    StockList finalOne;
    StockList finalTwo;
    for(int i = 0; i < one.getSize(); i++){
        Date day = one[i]->getDate();
        int index = two.find(day);

        // If the day is between the interval shared between the 2 stocks, and both stocks were reported on that day
        if((day >= globalStart && day <= globalEnd) && index != -1){
           finalOne.append(*one[i]);
           finalTwo.append(*two[index]);
           amount++;
        }
    }
    cout << "Number of trading days: " << amount << endl;

     cout << endl;

    cout << "Initial Investment in Company 1: ";
    cin >> initOne;
    cout << "Initial Investment in Company 2: ";
    cin >> initTwo;
    cout << "Percent to move on each transaction: ";
    cin >> per;

    cout << endl;


    double initialStockOne = initOne / finalOne[0]->getOpen();
    double initialStockTwo = initTwo / finalTwo[0]->getOpen();

    daily(initialStockOne, initialStockTwo, finalOne, finalTwo, per);

    cout << endl;

    multiDays(initialStockOne, initialStockTwo, finalOne, finalTwo, per, 5);

    cout << endl;

    multiDays(initialStockOne, initialStockTwo, finalOne, finalTwo, per, 10);

    cout << endl;

    multiDays(initialStockOne, initialStockTwo, finalOne, finalTwo, per, 30);

    return 0;
}

/*
Description: Loads the given files into a the input StockList
Parameters:
            (ifstream) &file: file to be loaded
            (Stocklist) &obj: StockList to load into
Return:
            None
Notes:
*/
void loadDataFile(ifstream &file, StockList &obj){
    string details, data;

    // Skip the header line
    getline(file, details);

    while(getline(file, details)){
        stringstream ss(details);

        // pick apart the string comma by comma
        string dateStr;
        getline(ss, dateStr, ',');

        stringstream dts(dateStr);
        string year;
        string month;
        string day;
        getline(dts, year, '-');
        getline(dts, month, '-');
        getline(dts, day, '-');

        Date date(stoi(month), stoi(day), stoi(year));

        // Open
        string openStr;
        getline(ss, openStr, ',');

        // High
        string highStr;
        getline(ss, highStr, ',');

        // Low
        string lowStr;
        getline(ss, lowStr, ',');

        // Close
        string closeStr;
        getline(ss, closeStr, ',');

        // Adj close
        string adjClsStr;
        getline(ss, adjClsStr, ',');

        // Volume
        string volumeStr;
        getline(ss, volumeStr, ',');

        //cout << volumeStr << endl;
        StockDay sd(date, stod(openStr), stod(closeStr), stod(adjClsStr), stod(highStr), stod(lowStr), stoul(volumeStr));
        obj.append(sd);
    }
    file.close();
}


/*
Description: Returns true or false whether or not the stock is down for the day
Parameters:
            (StockDay) sd: StockDay to be analyzed
Return:
            (bool): Is the stock down?
Notes:
*/
bool isDown(StockDay sd){
    return sd.getOpen() > sd.getClose();
}


/*
Description: Returns true or false whether or not the stock is up for the day
Parameters:
            (StockDay) sd: StockDay to be analyzed
Return:
            (bool): Is the stock up?
Notes:
*/
bool isUp(StockDay sd){
    return sd.getOpen() < sd.getClose();
}

/*
Description: Analyzes the two stock days and returns wither or not the stock is up for the given period between the days
Parameters:
            (StockDay) sd1: first StockDay to be analyzed
            (StockDay) sd2: second StockDay to compare
Return:
            (bool): Is the stock up?
Notes:
*/
bool isUp(StockDay sd1, StockDay sd2){
    return sd1.getClose() > sd2.getOpen();
}

/*
Description: Analyzes the two stock days and returns wither or not the stock is down for the given period between the days
Parameters:
            (StockDay) sd1: first StockDay to be analyzed
            (StockDay) sd2: second StockDay to compare
Return:
            (bool): Is the stock down?
Notes:
*/
bool isDown(StockDay sd1, StockDay sd2){
    return sd1.getClose() < sd2.getOpen();
}

/*
Description: Runs a simulation for every day, selling off the input percentage of the most epensive stock of the two, and buying the cheapest one with what money you made
             from sales.
Parameters:
            (double) initialOne: initial amount of stock 1 bought
            (double) initialTwo: initial amount of stock 2 bought
            (StockList) one: List of the first stock
            (StockList) two: List of the second stock
            (double) per: percentage of stock to sell
Return:
            None
Notes:
*/
void daily(double initialOne, double initialTwo, StockList one, StockList two, double per){
    cout << "Daily Buy/Sell Simulation" << endl;
    cout << "Initial Shares in Company 1: " << initialOne << endl;
    cout << "Initial Shares in Company 2: " << initialTwo << endl;

    // Save for later
    double preOne = initialOne;
    double preTwo = initialTwo;

    // Convert into actual decimal
    per = per * 0.01;
    for(int i = 0; i < one.getSize(); i++){
        StockDay sd1 = *one[i];
        StockDay sd2 = *two[i];

        // If stock 1 is up, sell and buy stock 2
        if(isUp(sd1) && isDown(sd2)){
            double sold = initialOne * per;
            double made = sold * sd1.getClose();
            double bought = made / sd2.getClose();
            initialOne -= sold;
            initialTwo += bought;
            // If stock 2 is up, sell and buy stock 1
        } else if(isDown(sd1) && isUp(sd2)){
            double sold = initialTwo * per;
            double made = sold * sd2.getClose();
            double bought = made / sd1.getClose();
            initialTwo -= sold;
            initialOne += bought;
        }
    }

     //How much money your stocks are worth on the final day
    double invst = (initialOne * (*one[one.getSize() - 1]).getClose()) + (initialTwo * (*two[two.getSize() - 1]).getClose());

    // How much money your stocks would be worh if you never sold
    double nb = (preOne * (*one[one.getSize() - 1]).getClose()) + (preTwo * (*two[two.getSize() - 1]).getClose());
    cout << "Ending shares in company 1: " << initialOne << endl;
    cout << "Ending shares in company 2: " << initialTwo << endl;
    cout << "Total investment value: " << invst << endl;
    cout << "Total no buy/sell value: " << nb << endl;
    cout << "Total earned by trading: " << invst - nb << endl;
}

/*
Description: Runs a simulation for every x days input, selling off the input percentage of the most epensive stock of the two, and buying the cheapest one with what money
             you made from sales.
Parameters:
            (double) initialOne: initial amount of stock 1 bought
            (double) initialTwo: initial amount of stock 2 bought
            (StockList) one: List of the first stock
            (StockList) two: List of the second stock
            (double) per: percentage of stock to sell
            (int) days: days between each stock check
Return:
            None
Notes:
*/
void multiDays(double initialOne, double initialTwo, StockList one, StockList two, double per, int days){
    cout << "Simulation Buy/Sell Every " << days << " days" << endl;
    cout << "Initial Shares in Company 1: " << initialOne << endl;
    cout << "Initial Shares in Company 2: " << initialTwo << endl;

    // Save for later
    double preOne = initialOne;
    double preTwo = initialTwo;

    // Convert into actual decimal
    per = per * 0.01;

    // For every stock
    for(int i = days; i < one.getSize(); i += days){
        StockDay sd1 = *one[i];
        StockDay sd2 = *two[i];

        // If sd1 is up, sell and buy sd2
        if(isUp(sd1, *one[i - days]) && isDown(sd2, *two[i - days])){
            double sold = initialOne * per;
            double made = sold * sd1.getClose();
            double bought = made / sd2.getClose();
            initialOne -= sold;
            initialTwo += bought;

            // If sd2 is up, sell and buy s1
        } else if(isDown(sd1, *one[i - days]) && isUp(sd2, *two[i - days])){
            double sold = initialTwo * per;
            double made = sold * sd2.getClose();
            double bought = made / sd1.getClose();
            initialTwo -= sold;
            initialOne += bought;
        }
    }

    //How much money your stocks are worth on the final day
    double invst = (initialOne * (*one[one.getSize() - 1]).getClose()) + (initialTwo * (*two[two.getSize() - 1]).getClose());

    // How much money your stocks would be worh if you never sold
    double nb = (preOne * (*one[one.getSize() - 1]).getClose()) + (preTwo * (*two[two.getSize() - 1]).getClose());
    cout << "Ending shares in company 1: " << initialOne << endl;
    cout << "Ending shares in company 2: " << initialTwo << endl;
    cout << "Total investment value: " << invst << endl;
    cout << "Total no buy/sell value: " << nb << endl;
    cout << "Total earned by trading: " << invst - nb << endl;
}
