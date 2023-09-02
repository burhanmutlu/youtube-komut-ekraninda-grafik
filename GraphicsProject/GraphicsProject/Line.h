#pragma once

#include "Window.h"
#include <Windows.h>
#include "Debug.h"
#include "Point.h"
#include <list>
#include <iostream>
#include <iterator>

class Line
{
public:
	Line();
	void drawLine(int x1, int y1, int x2, int y2);
	void setColor(COLORREF color);
	void drawPoly(int n_points, std::list<Point*> points);
private:
	Window* w;
	Debug* d;
	COLORREF color;
};

