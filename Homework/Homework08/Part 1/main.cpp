/*
Author: Charles Reigle
Creation Date: 4/20/23
Last Update: 4/20/23
Description: Pascals triangle calculator
User Interface: Enter in n and k to find out what n choose k is equal to
Notes:
*/

#include <iostream>

using namespace std;

int pascal(int, int);

int main(){
    int n, k;
    cout << "Enter n and k (integer) with a space between them: ";
    cin >> n;
    cin >> k;

    cout << n << " choose " << k << " = " << pascal(n, k) << endl;

}

int pascal(int n, int k){
    // If we are starting in the beginning, the value is 1.
    if(k == 0) return 1;

    // If n is negative or = 0, or k is negative, the value is 0
    if(n <= 0 || k < 0) return 0;

    // Call pascal again to get the values of the numbers above n, k
    return pascal(n-1, k) + pascal(n-1, k-1);
}
