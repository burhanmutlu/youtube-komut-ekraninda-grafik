#pragma once

#include "Point.h"
#include "Line.h"

class Triangle
{
public:
	Triangle();
	void drawTriangle(Point* p1, Point* p2, Point* p3);
private:
	Line* l;
};

