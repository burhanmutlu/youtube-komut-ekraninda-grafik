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

	list<Point*> points = { new Point(0,0) };
	int N = 40;
	for (int i = 0; i < N; i++) {
		points.push_back(
			new Point(
				(rand() % 200) * M_PI,
				(rand() % 100) * M_PI * altinOran
			)
		);
	}


	l->drawPoly(40, points);


	w->~Window();

	return 0;
}
