#include "Cube.h"

Cube::Cube() {
	this->s = new Square();
	this->l = new Line();
}

void Cube::drawCube(Point* startPoint, int width, int height) {

	int ikinciDikdortgenBaslangicX = startPoint->x + (width / 2);
	int ikinciDikdortgenBaslangicY = startPoint->y + (height / 2);

	s->drawSquare(startPoint, width, height);
	s->drawSquare(new Point(ikinciDikdortgenBaslangicX, ikinciDikdortgenBaslangicY) , width, height);

	l->drawLine(startPoint->x, startPoint->y, ikinciDikdortgenBaslangicX, ikinciDikdortgenBaslangicY); //üst sol
	l->drawLine(startPoint->x + width, startPoint->y, ikinciDikdortgenBaslangicX + width, ikinciDikdortgenBaslangicY); //üst sað
	l->drawLine(startPoint->x, startPoint->y + height, ikinciDikdortgenBaslangicX, ikinciDikdortgenBaslangicY + height); // alt sol
	l->drawLine(startPoint->x + width, startPoint->y + height, ikinciDikdortgenBaslangicX + width, ikinciDikdortgenBaslangicY + height); //alt sað

}