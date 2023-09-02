#pragma once

#include "Point.h"
#include "Line.h"

class Square
{
public:
	Square();
	void drawSquare(Point* startPoint, int width, int height);
	void fillSquare(Point* startPoint, int width, int height,COLORREF color);
private:
	Line* line;
};

