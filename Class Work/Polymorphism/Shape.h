/*
 Author: Don Spickler
 Creation Date: 1/26/2022
 Last Update: 1/26/2022
 Description: Specification for the Shape class.
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>

using namespace std;

class Shape {
protected:
	string name;  // Name of the shape
	string color; // Color of the shape.

public:
	Shape(string n = "", string c = "Red");
	~Shape();

	string getName();
	void setName(string);

	// You need to specify these functions as virtual. This tells the compiler to look at the functions on runtime, not compile time. Otherwise, when you try and call the
	// Functions from a list of Shapes, it will call the parent version of the functions and not the overwritten child versions. Dyanmic binding
	virtual double Area();
	virtual void draw();
};

#endif /* SHAPE_H_ */
