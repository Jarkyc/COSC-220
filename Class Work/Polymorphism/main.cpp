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
#include "Square.h"
#include "Shape.h"

using namespace std;

int main() {

	// You can store "shapes" in an array by creating an array of POINTERS to shapes, and storing their pointers rather than their objects. Trying to store their objects, even if they are of the
	// same parent class, causes a compile error

	Shape *shapes[3] = { new Triangle(3, 4, 5, "Green"), new Rectangle(3, 4,
			"Blue"), new Square(5, "Light Gray") };

	for (int i = 0; i < 3; i++)
		shapes[i]->draw();

	for (int i = 0; i < 3; i++)
		delete shapes[i];

//	delete [] shapes;  // Not the way to go here.

	return 0;
}
