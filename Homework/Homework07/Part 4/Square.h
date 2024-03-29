/*
 Author: Don Spickler
 Creation Date: 1/26/2022
 Last Update: 1/26/2022
 Description: Specification for the Square class.
 */

#ifndef SQUARE_H_
#define SQUARE_H_

#include "Rectangle.h"

class Square : public Rectangle {
public:
	Square(double s = 0, string c = "Red");
	~Square();

	virtual void draw();
};

#endif /* SQUARE_H_ */
