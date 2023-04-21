/*
Author: Charles Reigle
Creation Date: 4/20/23
Last Update: 4/20/23
Description: A program to find out if a string is a palindrome
User Interface: Asks for a string to evaluate
Notes:
*/

#include <iostream>

using namespace std;

bool isPal(const string&, int, int);

int main(){

    string str;
    cout << "Enter a string, no spaces and all lower case: ";
    cin >> str;

    if(isPal(str, 0, str.length()-1)) cout << str << " is a palindrome" << endl;
    else cout << str << " is not a palindrome" << endl;

}

bool isPal(const string& str, int startIndex, int endIndex){
    if(str[startIndex] != str[endIndex]) return false;

    // If the string is even length, the indexes will be right next to eachother when they meet. Saves runtime.
    if(startIndex == endIndex-1) return true;

    // If the string is odd length, the indexes will converge on the same point. Saves runtime.
    if(startIndex == endIndex) return true;


    return isPal(str, startIndex+1, endIndex-1);

}
