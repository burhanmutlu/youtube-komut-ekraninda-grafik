#pragma once

#include <Windows.h>
#include "Window.h"

#define BLACK RGB(0,0,0)
#define WHITE RGB(255,255,255)

struct colorSt {
		int R;
		int G;
		int B;
};

enum BgColors {
	Black, 
	Blue,  
	Green, 
	Aqua,  
	Red,   
	Purple,
	Yellow,
	White, 
	Gray,
	LightBlue,
	LightGreen,
	LightAqua,
	LightRed,
	LightPurple,
	LightYellow,
	BrightWhite
};


class Color
{
public:
	
	Color();
	colorSt GetColor(int x, int y);
	COLORREF colorsValue[16];
private:
	Window* w;
};

