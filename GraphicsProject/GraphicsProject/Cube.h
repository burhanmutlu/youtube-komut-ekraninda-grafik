#pragma once

#include "Point.h"
#include "Square.h"

class Cube
{
public:
	Cube();
	void drawCube(Point* startPoint, int width, int height);
private:
	Square* s;
	Line* l;
};

