/*
 Author: Don Spickler
 Creation Date: 1/26/2022
 Last Update: 1/26/2022
 Description: Testing program for inheritance.
 User Interface: None
 */

#include <iostream>

#include "Triangle.h"
#include "Rectangle.h"
#include "Shape.h"

using namespace std;

int main() {
	Triangle Tri1;
	Triangle Tri2(3, 4, 5);
	Triangle Tri3(3, 4, 8);
	Rectangle rect1(3, 4);
	Shape shape1;

	Tri1.draw();
	Tri2.draw();
	rect1.draw();
	shape1.draw();

	cout << "Area of Tri1 = " << Tri1.Area() << endl;
	cout << "Area of Tri2 = " << Tri2.Area() << endl;
	cout << "Area of rect1 = " << rect1.Area() << endl;
	cout << "Area of shape1 = " << shape1.Area() << endl;

	cout << "Is Tri1 a triangle: " << Tri1.isTriangle() << endl;
	cout << "Is Tri3 a triangle: " << Tri3.isTriangle() << endl;

	return 0;
}
