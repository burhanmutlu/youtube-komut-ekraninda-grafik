#pragma once

#include "Point.h"
#include "Line.h"

class Square
{
public:
	Square();
	void drawSquare(Point* startPoint, int width, int height);
private:
	Line* line;
};

