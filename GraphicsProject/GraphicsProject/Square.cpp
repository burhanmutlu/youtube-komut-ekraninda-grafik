#include "Square.h"

Square::Square() {
	this->line = new Line();
}

void Square::drawSquare(Point* startPoint, int width, int height) {
	line->drawLine(startPoint->x, startPoint->y, startPoint->x + width, startPoint->y);
	line->drawLine(startPoint->x, startPoint->y, startPoint->x, startPoint->y + height);
	line->drawLine(startPoint->x, startPoint->y + height, startPoint->x + width, startPoint->y + height);
	line->drawLine(startPoint->x + width, startPoint->y, startPoint->x + width, startPoint->y + height);
}

