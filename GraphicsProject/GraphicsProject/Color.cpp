#include "Color.h"

Color::Color() {
	w = new Window();
	colorsValue[0] = RGB(0, 0, 0);
	colorsValue[1] = RGB(0, 55, 218);
	colorsValue[2] = RGB(19, 161, 14);
	colorsValue[3] = RGB(58, 150, 221);
	colorsValue[4] = RGB(197, 15, 31);
	colorsValue[5] = RGB(136, 23, 152);
	colorsValue[6] = RGB(193, 156, 0);
	colorsValue[7] = RGB(204, 204, 204);
	colorsValue[8] = RGB(118, 118, 118);
	colorsValue[9] = RGB(59, 120, 255);
	colorsValue[10] = RGB(22, 198, 12);
	colorsValue[11] = RGB(97, 214, 214);
	colorsValue[12] = RGB(231, 72, 86);
	colorsValue[13] = RGB(180, 0, 158);
	colorsValue[14] = RGB(249, 241, 165);
	colorsValue[15] = RGB(242, 242, 242);
}



colorSt Color::GetColor(int x, int y) {
	COLORREF color = GetPixel(w->getconsoleDC(), x, y);
	colorSt c;
	c.R = (int)GetRValue(color);
	c.G = (int)GetGValue(color);
	c.B = (int)GetBValue(color);
	return c;
}
