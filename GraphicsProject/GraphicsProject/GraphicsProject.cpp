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





	w->~Window();

	return 0;
}
