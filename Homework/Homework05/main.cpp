/*
Author: Charles Reigle
Creation Date: 3/16/23
Last Update: 3/16/23
Description: PersonData, CustomerData, PreferredCustomer usage
User Interface: Menu of actions that user can take (adding personal data, adding customer data, adding a preferred customer, print the database in long format, print the database in short format, quit)
Notes: 
*/
#include "PersonData.h"
#include "CustomerData.h"
#include "PreferredCustomer.h"
#include "string"

using namespace std;

int main(){
    
    int answer;
    int databaseSize = 0;
    PersonData *db[10];
    while(true){
        // Don't let it go past 10
        if(databaseSize == 10) break;
        cout << "1. Add Personal Data Object" << endl;
        cout << "2. Add Customer Data Object" << endl;
        cout << "3. Add Preferred Customer Data Object" << endl;
        cout << "4. View Database Long Form" << endl;
        cout << "5. View Database Short Form" << endl;
        cout << "6. Quit" << endl;
        cin >> answer;

        string first;
        string last;
        string address;
        string city;
        string state;
        string zip;
        string phone;

        switch(answer){
            case 1:
            {
                string first;
                string last;
                string address;
                string city;
                string state;
                string zip;
                string phone;
                cout << "Input Last Name: ";
                cin >> last;
                cout << "Input Fist Name: ";
                cin >> first;
                cin.ignore();
                cout << "Input Street Address: ";
                getline(cin, address);
                cout << "Input City: ";
                cin >> city;
                cout << "Input State: ";
                cin >> state;
                cout << "Input Zip Code: ";
                cin >> zip;
                cout << "Input Phone Number: ";
                cin >> phone;

                PersonData *pd = new PersonData(first, last, state, city, address, phone, zip);
                db[databaseSize] = pd;
                databaseSize++;
                break;
            }
            case 2:
            {
                string number;
                string ml;
                bool mail;

                cout << "Input Last Name: ";
                cin >> last;
                cout << "Input Fist Name: ";
                cin >> first;
                cin.ignore();
                cout << "Input Street Address: ";
                getline(cin, address);
                cout << "Input City: ";
                cin >> city;
                cout << "Input State: ";
                cin >> state;
                cout << "Input Zip Code: ";
                cin >> zip;
                cout << "Input Phone Number: ";
                cin >> phone;
                cout << "Input Customer Number: ";
                cin >> number;
                cout << "Do they wish to be on the mailing list? (Y/N): ";
                cin >> ml;

                if(ml == "Y" || ml == "y") mail = true;
                else mail = false;

                CustomerData *cd = new CustomerData(first, last, state, city, address, phone, zip, stoi(number), mail);
                db[databaseSize] = cd;
                databaseSize++;
                break;
            }
            case 3:
            {
                string number;
                string ml;
                string spent;
                bool mail;

                cout << "Input Last Name: ";
                cin >> last;
                cout << "Input Fist Name: ";
                cin >> first;
                cin.ignore();
                cout << "Input Street Address: ";
                getline(cin, address);
                cout << "Input City: ";
                cin >> city;
                cout << "Input State: ";
                cin >> state;
                cout << "Input Zip Code: ";
                cin >> zip;
                cout << "Input Phone Number: ";
                cin >> phone;
                cout << "Input Customer Number: ";
                cin >> number;
                cout << "Do they wish to be on the mailing list? (Y/N): ";
                cin >> ml;
                do{
                    cout << "Input Purchase Amount: ";
                    cin >> spent;
                }while(stod(spent) < 0);

                if(ml == "Y" || ml == "y") mail = true;
                else mail = false;

                PreferredCustomer *pc = new PreferredCustomer(first, last, state, city, address, phone, zip, stoi(number), mail, stod(spent));
                db[databaseSize] = pc;
                databaseSize++;
                break;
            }
            case 4:
            {
                for(int i = 0; i < databaseSize; i++){
                    db[i]->PrintRecord();
                    cout << endl;
                }
                break;
            }
            case 5:
            {
                for(int i = 0; i < databaseSize; i++){
                    cout << db[i]->getRecord() << endl;
                }
                break;
            }
            case 6:
                return 0;
            default:
                continue;
        }

    }

    return 0;

}
