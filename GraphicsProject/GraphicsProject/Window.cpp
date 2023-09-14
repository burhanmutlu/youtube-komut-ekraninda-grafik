#include "Window.h"

#include <iostream>
#include <list>
#include<iterator>

Window::Window() {
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	consoleWindow = GetConsoleWindow();
	consoleDC = GetDC(consoleWindow);
	hideCursor();
}

Window::~Window() {
	ReleaseDC(consoleWindow, consoleDC);
	std::cin.ignore();
}

void Window::hideCursor() {
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

HDC Window::getconsoleDC() {
	return consoleDC;
}


int Window::getWindowWidth() {
	GetConsoleScreenBufferInfo(consoleHandle, &csbi);
	width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	return width*8;
}

int Window::getWindowHeight() {
	GetConsoleScreenBufferInfo(consoleHandle, &csbi);
	height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	return height*16;
}

void Window::setBgColor(COLORREF bgColor) {
	this->bgColor = bgColor;
}

COLORREF Window::getBgColor() {
	return bgColor;
}

void Window::funmap() {
	srand(time(NULL));
	static COLORREF myMap[8*120][16*30];
	for (int y = 0; y < 16 * 30; y++) {
		for (int x = 0; x < 8 * 120; x++) {
			myMap[x][y] = (COLORREF)RGB(0,0, rand() % 255);
		}
	}

	for (int y = 0; y < 16 * 30; y++) {
		for (int x = 0; x < 8 * 120; x++) {
			SetPixel(consoleDC, x, y, myMap[x][y]);
		}
	}

	std::list<int> xlist;
	std::list<int> ylist;
	for (int y = 0; y < getWindowHeight() * 16; y++) {
		for (int x = 0; x < getWindowWidth() * 8; x++) {
			if ( !(myMap[x][y] == (COLORREF)RGB(0, 0, 0)) ) {
				xlist.push_back(x);
				ylist.push_back(y);
			}
		}
	}

	std::list<int>::iterator it;
	std::list<int>::iterator itt;
	for (itt = ylist.begin(); itt != ylist.end(); ++itt) {
		for (it = xlist.begin(); it != xlist.end(); ++it) {
			SetPixel(consoleDC, *it, *itt, (COLORREF)RGB(255, 255, 255));
		}
	}

		
}

void Window::clearDevice() {
	
	DWORD mode = 0;

	const DWORD originalMode = mode;
	mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

	DWORD written = 0;
	PCWSTR sequence = L"\x1b[2J";
	if (!WriteConsoleW(consoleHandle, sequence, (DWORD)wcslen(sequence), &written, NULL))
	{
		SetConsoleMode(consoleHandle, originalMode);
	}

	SetConsoleMode(consoleHandle, originalMode);

}
