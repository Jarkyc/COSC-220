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

	double Area();
	void draw();
};

#endif /* SHAPE_H_ */
