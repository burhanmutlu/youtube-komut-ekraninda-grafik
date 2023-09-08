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

	
	COLORREF colorref[] = {RGB(255,255,255),RGB(255,255,255),RGB(255,180,88),RGB(53,24,0),RGB(4,66,120),RGB(146,199,246),RGB(255,255,255),RGB(255,255,255),RGB(255,255,184),RGB(74,0,0),RGB(12,100,161),RGB(120,81,47),RGB(95,100,115),RGB(138,196,246),RGB(255,255,255),RGB(255,244,220),RGB(255,255,255),RGB(255,255,255),RGB(255,255,253),RGB(190,114,49),RGB(79,92,114),RGB(138,196,246),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(255,255,242),RGB(182,109,47),RGB(79,92,114),RGB(138,196,246),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(255,255,242),RGB(182,109,47),RGB(79,92,114),RGB(138,196,246),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(255,255,242),RGB(182,109,47),RGB(79,92,114),RGB(138,196,246),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(255,255,242),RGB(182,109,47),RGB(79,92,114),RGB(138,196,246),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(255,255,255),RGB(205,125,56),RGB(91,106,129),RGB(156,220,255),RGB(255,255,255),RGB(255,255,251),RGB(255,255,193),RGB(97,0,0),RGB(0,0,0),RGB(0,0,0),RGB(0,0,0),RGB(0,0,0),RGB(0,15,44),RGB(93,152,201)};

	int index = 0;
	for (int y = 20; y < 29; y++) {
		for (int x = 20; x < 28; x++) {
			SetPixel(w->getconsoleDC(), x, y, colorref[index]);
			index += 1;
		}
	}
	



	// pong game
	
	/*int kenarYukseklik = w->getWindowHeight() / 30;
	int x = w->getWindowWidth() / 2;
	int y = w->getWindowHeight() / 2;
	int dx = 5;
	int dy = 5;
	int raketX = 20;
	int raketY = w->getWindowHeight() / 2 - 25;
	int raketArttirmaDegeri = 20;
	int raketUzunluk = 50;
	int raketGenislik = 10;
	char tus = ' ';
	struct colorSt colormy;
	colormy.R = 0;
	colormy.G = 0;
	colormy.B = 0;
	int otoRaketX = w->getWindowWidth() - 20 - 10;
	int otoRaketY = w->getWindowHeight() / 2 - 30;
	int otoDy = 5;
	int topBoyut = 15;

	// alan cizimi
	s->fillSquare(new Point(0, 0), w->getWindowWidth(), w->getWindowHeight() / 30, RGB(255, 255, 255));
	s->fillSquare(new Point(0, w->getWindowHeight() - kenarYukseklik), w->getWindowWidth(), kenarYukseklik, RGB(255, 255, 255));

	for (int i = 0; i < 14; i++) {
		s->fillSquare(new Point(w->getWindowWidth() / 2, 20 + i * (topBoyut+10)), topBoyut, topBoyut, RGB(255, 255, 255));
	}

	while (true) {

		// oyun hareketleri
		s->fillSquare(new Point(raketX,raketY), 10, raketUzunluk, RGB(255, 255, 255)); // ilk raket
		s->fillSquare(new Point(otoRaketX, otoRaketY), 10, raketUzunluk, RGB(255, 255, 255)); //2.raket

		// top hareketleri
		s->fillSquare(new Point(x, y), topBoyut, topBoyut, RGB(255, 255, 0));//top
		Sleep(1000/60); // 60 fps degerinde calissin
		s->fillSquare( new Point(x, y), topBoyut, topBoyut,RGB(0,0,0) ); //top

		// raket hareketleri
		
		if (_kbhit()) { // tiklanma varsa calissin
			tus = (char)_getch();
		}
		
		if (tus == 'w' && raketY >= kenarYukseklik) { // yukari dogru hareket raket1
			s->fillSquare(new Point(raketX, raketY), raketGenislik, raketUzunluk, RGB(0, 0, 0));
			raketY = raketY - raketArttirmaDegeri;
			s->fillSquare(new Point(raketX, raketY), raketGenislik, raketUzunluk, RGB(255, 255, 255));
		}
		if (tus == 's' && raketY <= w->getWindowHeight() - (kenarYukseklik + raketUzunluk)) { // asagi dogru hareket raket1
			s->fillSquare(new Point(raketX, raketY), raketGenislik, raketUzunluk, RGB(0, 0, 0));
			raketY = raketY + raketArttirmaDegeri;
			s->fillSquare(new Point(raketX, raketY), raketGenislik, raketUzunluk, RGB(255, 255, 255));
		}

		
		if (y>= otoRaketY) {
			s->fillSquare(new Point(otoRaketX, otoRaketY), raketGenislik, raketUzunluk, RGB(0, 0, 0));
			otoRaketY = otoRaketY + otoDy;
			s->fillSquare(new Point(otoRaketX, otoRaketY), raketGenislik, raketUzunluk, RGB(255, 255, 255));
		}
		else if(y <= otoRaketY) {
			s->fillSquare(new Point(otoRaketX, otoRaketY), raketGenislik, raketUzunluk, RGB(0, 0, 0));
			otoRaketY = otoRaketY - otoDy;
			s->fillSquare(new Point(otoRaketX, otoRaketY), raketGenislik, raketUzunluk, RGB(255, 255, 255));
		}
		else {
			otoRaketY = otoRaketY;
		}
		

		// arttirma kisimlari

		if (tus != ' ') {
			tus = ' ';
		}

		if ( (x >= otoRaketX && y >= (otoRaketY - topBoyut) && y <= (otoRaketY + raketUzunluk) ) ||
		   ( (x <= raketX) && (y>= (raketY-topBoyut) && y<=(raketY + raketUzunluk) ) )
		){
			dx = dx * -1;
		}

		if (y >= (w->getWindowHeight() - kenarYukseklik - 20) || y <= (0 + kenarYukseklik)) {
			dy = dy * -1;
		}
		x = x + dx;
		y += dy;
		
	}
	*/




	w->~Window();

	return 0;
}
