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
	
	long double altinOran = 1.618033988749894L;

	list<Point*> points =  { new Point(0,0) };
	int N = 40;
	for (int i = 0; i < N; i++) {
		points.push_back ( 
			new Point( 
				(rand() % 200) * M_PI ,
				(rand() % 100) * M_PI * altinOran
			) 
		);
	}


	//l->drawPoly(40, points);

	int width  = 200;
	int height = 200;
	int x = 20, y = 20;

	s->drawSquare(new Point(x, y), width, height);

	s->drawSquare(new Point( x + (width / 2), y + (height / 2) ), width, height);

	l->drawLine(x, y, x + (width / 2), y + (height / 2)); //üst sol
	l->drawLine(x+width, y, x + (width / 2) + width, y + (height / 2)); //üst sağ
	l->drawLine(x, y + height, x + (width / 2), y + (height / 2) + height); // alt sol
	l->drawLine(x+width, y+height, x + (width / 2)+width, y + (height / 2) +height); //alt sağ







	w->~Window();

	return 0;
}
