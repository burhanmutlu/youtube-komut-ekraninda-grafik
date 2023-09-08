#pragma once

#include <Windows.h>
#include "Window.h"

struct colorSt {
		int R;
		int G;
		int B;
};

class Color
{
public:
	
	Color();
	colorSt GetColor(int x, int y);
	
private:
	Window* w;
};

