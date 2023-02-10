// Textbook example with some minor alterations.
// Date: 1/22/2022

// Implementation file for the Rectangle class.

#include "Rectangle.h"   // Needed for the Rectangle class. Implementation needs to know whats in the .h

using namespace std;

//***********************************************************
// setWidth sets the value of the member variable width.    *
//***********************************************************

void Rectangle::setWidth(double w) {
	if (w >= 0)
		width = w;
	else {
		cout << "Invalid width: no change made.\n";
	}
}

//***********************************************************
// setLength sets the value of the member variable length.  *
//***********************************************************

void Rectangle::setLength(double len) {
	if (len >= 0)
		length = len;
	else {
		cout << "Invalid length: no change made.\n";
	}
}

//***********************************************************
// getWidth returns the value in the member variable width. *
//***********************************************************

double Rectangle::getWidth() const {
	return width;
}

//*************************************************************
// getLength returns the value in the member variable length. *
//*************************************************************

double Rectangle::getLength() const {
	return length;
}

//************************************************************
// getArea returns the product of width times length.        *
//************************************************************

double Rectangle::getArea() const {
	return width * length;
}
