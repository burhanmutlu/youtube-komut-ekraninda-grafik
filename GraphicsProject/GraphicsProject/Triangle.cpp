#include "Triangle.h"

Triangle::Triangle() {
	this->l = new Line();
}

void Triangle::drawTriangle(Point* p1, Point* p2, Point* p3) {
	l->drawLine(p1->x, p1->y, p2->x, p2->y);
	l->drawLine(p2->x, p2->y, p3->x, p3->y);
	l->drawLine(p3->x, p3->y, p1->x, p1->y);
}
