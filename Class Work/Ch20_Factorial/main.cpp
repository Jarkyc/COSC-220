#include <iostream>

using namespace std;

int factorial(int n) {
	if (n == 0)
		return 1;                    // Base case
	else
		return n * factorial(n - 1); // Recursive case
}

int factorialPrint(int n) {
	int fact = 1;
	cout << "In factorial n = " << n << endl;

	if (n != 0)
		fact = n * factorialPrint(n - 1);

	cout << "Out factorial n = " << n << endl;

	return fact;
}

int main() {
	int number;

	cout << "Enter an integer: ";
	cin >> number;

	cout << number << "! = " << factorial(number) << endl;
	//cout << number << "! = " << factorialPrint(number) << endl;

	return 0;
}

