/*
Author: Charles Reigle
Creation Date: 3/13/2023
Last Update: 3/15/2023
Description: Program that gets the statistics of a companies stock
User Interface: File name to open
Notes:
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include "Date.h"
#include "StockDay.h"
#include "StockList.h"

using namespace std;

void loadDataFile(StockList&);

string PATH = "data/";
ifstream file;

int main(){

    string fileName = "";
    StockList obj;

    cout << "File to load: ";
    cin >> fileName;

    PATH += fileName;

    file.open(PATH);
    if(!file.good()){
        cout << "File does not exist. Exiting program." << endl;
        return 0;
    }

    loadDataFile(obj);

    // In case the dates are not in sequential order
    int amount = obj.getSize();
    Date begin = (*obj[0]).getDate();
    Date end(0, 0, 0000);
    double openAvg, closeAvg, highAvg, lowAvg, volAvg, bs = 0;
    int upDays = 0, downDays = 0, neutralDays = 0;

    // Evaluate every single day
    for(int i = 0; i < amount; i++){
        StockDay day = *obj[i];
        if(day.getDate() > end) end = day.getDate();
        if(day.getDate() < begin) begin = day.getDate();

        openAvg += day.getOpen();
        closeAvg += day.getClose();
        highAvg += day.getHigh();
        lowAvg += day.getLow();
        volAvg += day.getVolume();

        if(day.getOpen() < day.getClose()) upDays++;
        if(day.getOpen() > day.getClose()) downDays++;
        if(day.getOpen() == day.getClose()) neutralDays++;

        bs += day.getClose() - day.getOpen();

    }

    double costPerDay = openAvg;
    double finalClose = (*obj[obj.getSize() - 1]).getClose();

    openAvg = openAvg / amount;
    closeAvg = closeAvg / amount;
    highAvg = highAvg / amount;
    lowAvg = lowAvg / amount;
    volAvg = volAvg / amount;

    cout << fixed << endl;
    cout << "Summary Statistics" << endl;
    cout << "-------------------------" << endl;
    cout << "Number Of Days: " << amount << endl;
    cout << "Date Range: " << begin << " to " << end << endl;
    cout << "Up Days: " << upDays << endl;
    cout << "Down Days: " << downDays << endl;
    cout << "Neutral Days: " << neutralDays << endl;
    cout << "Average Opening Value: " << openAvg << endl;
    cout << "Average Closing Value: " << closeAvg << endl;
    cout << "Average High Value: " << highAvg << endl;
    cout << "Average Low Vale: " << lowAvg << endl;
    cout << "Average Volume: " << volAvg << endl;

    cout << endl;

    cout << "Stock Per Day Investment Scheme" << endl;
    cout << "-------------------------" << endl;
    cout << "Stock Per Day Cost: " << costPerDay << endl;
    cout << "Stock Per Day Shares: " << amount << endl;
    cout << "Stock Per Day Worth: " << finalClose * amount << endl;

    cout << endl;

    cout << "Buy/Sell Investment Scheme" << endl;
    cout << "-------------------------" << endl;
    cout << "Buy/Sell Worth: " << bs << endl;

    return 0;
}

void loadDataFile(StockList &obj){
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
