#include "Color.h"

Color::Color() {
	w = new Window();
	colorsValue[0] = RGB(0, 0, 0);
	colorsValue[1] = RGB(0, 0, 255);
	colorsValue[2] = RGB(0, 128, 0);
	colorsValue[3] = RGB(0, 255, 255);
	colorsValue[4] = RGB(255, 0, 0);
	colorsValue[5] = RGB(128, 0, 128);
	colorsValue[6] = RGB(255, 255, 0);
	colorsValue[7] = RGB(255, 255, 255);
	colorsValue[8] = RGB(128, 128, 128);
	colorsValue[9] = RGB(173, 216, 230);
	colorsValue[10] = RGB(144, 238, 144);
	colorsValue[11] = RGB(173, 216, 230);
	colorsValue[12] = RGB(255, 182, 193);
	colorsValue[13] = RGB(221, 160, 221);
	colorsValue[14] = RGB(255, 255, 224);
	colorsValue[15] = RGB(255, 255, 255);
}



colorSt Color::GetColor(int x, int y) {
	COLORREF color = GetPixel(w->getconsoleDC(), x, y);
	colorSt c;
	c.R = (int)GetRValue(color);
	c.G = (int)GetGValue(color);
	c.B = (int)GetBValue(color);
	return c;
}
