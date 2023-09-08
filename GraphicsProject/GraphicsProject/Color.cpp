#include "Color.h"

Color::Color() {
	w = new Window();
}



colorSt Color::GetColor(int x, int y) {
	COLORREF color = GetPixel(w->getconsoleDC(), x, y);
	colorSt c;
	c.R = (int)GetRValue(color);
	c.G = (int)GetGValue(color);
	c.B = (int)GetBValue(color);
	return c;
}
