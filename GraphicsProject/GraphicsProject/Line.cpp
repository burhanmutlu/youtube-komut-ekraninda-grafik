#include "Line.h"
#include <stdexcept>

Line::Line() {
    this->w = new Window();
    this->d = new Debug();
    color = RGB(255, 255, 255);
}

void Line::drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int error = dx - dy;

    while (x1 != x2 || y1 != y2) {
        // Çizgiyi çiz
        SetPixel(this->w->getconsoleDC(), x1, y1, color);

        int doubleError = error * 2;

        if (doubleError > -dy) {
            error -= dy;
            x1 += sx;
        }
        if (doubleError < dx) {
            error += dx;
            y1 += sy;
        }
    }
    // Son noktayý çiz
    SetPixel(this->w->getconsoleDC(), x2, y2, color);
}

void Line::setColor(COLORREF color) {
    this->color = color;
}


void Line::drawPoly(int n_points, std::list<Point*> points) {
    std::list<Point*>::iterator itr = points.begin();
    std::list<Point*>::iterator itr2 = itr;
    itr2++;
    if (n_points <= 1) {
        this->d->log("Nokta deðeri 1'den büyük olmak zorundadýr.");
        throw std::invalid_argument("Nokta deðeri 1'den büyük olmak zorundadýr.");
    }
   
    for (int i = 0; i < n_points; i++) {
        this->color = RGB(rand() % 255, rand() % 255, rand() % 255);
        drawLine((*itr)->x, (*itr)->y, (*itr2)->x, (*itr2)->y);
        itr++; itr2++;
        Sleep(10);
    }
}