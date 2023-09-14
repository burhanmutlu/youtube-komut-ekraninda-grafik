#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "Graphics.h"
#include <conio.h>
#include <list>

using namespace std;

Window* w = new Window();

int main()
{
	srand(time(NULL));
	Time* t = new Time();
	Debug* d = new Debug();
	Circle* c = new Circle();
	Line* l = new Line();
	Triangle* triangle = new Triangle();
	Square* s = new Square();
	Cube* cube = new Cube();
	Color* color = new Color();

	
	/*COLORREF colorref[] = {RGB(255,255,255),RGB(255,255,255),RGB(255,180,88),RGB(53,24,0),RGB(4,66,120),RGB(146,199,246),RGB(255,255,255),RGB(255,255,255),RGB(255,255,184),RGB(74,0,0),RGB(12,100,161),RGB(120,81,47),RGB(95,100,115),RGB(138,196,246),RGB(255,255,255),RGB(255,244,220),RGB(255,255,255),RGB(255,255,255),RGB(255,255,253),RGB(190,114,49),RGB(79,92,114),RGB(138,196,246),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(255,255,242),RGB(182,109,47),RGB(79,92,114),RGB(138,196,246),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(255,255,242),RGB(182,109,47),RGB(79,92,114),RGB(138,196,246),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(255,255,242),RGB(182,109,47),RGB(79,92,114),RGB(138,196,246),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(255,255,242),RGB(182,109,47),RGB(79,92,114),RGB(138,196,246),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(205,125,56),RGB(91,106,129),RGB(156,220,255),RGB(255,255,255),RGB(255,255,251),RGB(255,255,193),RGB(97,0,0),RGB(0,0,0),RGB(0,0,0),RGB(0,0,0),RGB(0,0,0),RGB(0,15,44),RGB(93,152,201)};

	int index = 0;
	for (int y = 20; y < 29; y++) {
		for (int x = 20; x < 28; x++) {
			SetPixel(w->getconsoleDC(), x, y, colorref[index]);
			index += 1;
		}
	}*/
	

	PongGame* pongGame = new PongGame();

	pongGame->drawScene();
	pongGame->setGameSpeed(medium);
	pongGame->setBgColor(Red);

	pongGame->play();
	





	w->~Window();

	return 0;
}
