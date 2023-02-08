// Textbook example with some minor alterations.
// Date: 1/22/2022

// Specification file for the Rectangle class.

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>      // Needed for cout

// Rectangle class declaration.

class Rectangle {
private:
	double width;
	double length;

public:
	void setWidth(double);
	void setLength(double);
	double getWidth() const;
	double getLength() const;
	double getArea() const;
};

#endif
