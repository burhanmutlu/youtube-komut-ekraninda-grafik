#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "Graphics.h"
#include <conio.h>

using namespace std;

Window* w = new Window();

void drawline(int x0, int y0, int x1, int y1)
{
	int dx, dy, p, x, y;

	dx = x1 - x0;
	dy = y1 - y0;

	x = x0;
	y = y0;

	p = 2 * dy - dx;

	while (x <= x1)
	{
		if (p >= 0)
		{
			SetPixel(w->getconsoleDC(), x, y, RGB(255, 255, 255));
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			SetPixel(w->getconsoleDC(), x, y, RGB(255, 255, 255));
			p = p + 2 * dy;
		}
		x = x + 1;
	}
}

void bresenham(int x1, int y1, int x2, int y2)
{
	int m_new = 2 * (y2 - y1);
	int slope_error_new = m_new - (x2 - x1);
	for (int x = x1, y = y1; x <= x2; x++) {
		SetPixel(w->getconsoleDC(), x, y, RGB(255, 255, 255));

		// Add slope to increment angle formed
		slope_error_new += m_new;

		// Slope error reached limit, time to
		// increment y and update slope error.
		if (slope_error_new >= 0) {
			y++;
			slope_error_new -= 2 * (x2 - x1);
		}
	}
}


int main()
{
	
	Time* t = new Time();
	Debug* d = new Debug();
	Circle* c = new Circle();

	
	//drawline(
	//	20, 20, 
	//	220, 450
	//);

	bresenham(
		20, 20,
		100, 200
	);






	w->~Window();

	return 0;
}
