#include "PongGame.h"

PongGame::PongGame() {
	w = new Window();
	s = new Square();
	c = new Color();
	kenarYukseklik = w->getWindowHeight() / 30;
	x = w->getWindowWidth() / 2;
	y = w->getWindowHeight() / 2;
	dx = 10;
	dy = 10;
	raketX = 20;
	raketY = w->getWindowHeight() / 2 - 25;
	raketArttirmaDegeri = 20;
	raketUzunluk = 50;
	raketGenislik = 10;
	tus = ' ';
	otoRaketX = w->getWindowWidth() - 20 - 10;
	otoRaketY = w->getWindowHeight() / 2 - 30;
	otoDy = 10;
	topBoyut = 15;
	gameSpeed = 60;
	bgColor = BLACK;
	pixelColor = WHITE;
}

void PongGame::drawScene() {
	// alan cizimi
	s->fillSquare(new Point(0, 0), w->getWindowWidth(), w->getWindowHeight() / 30, pixelColor);
	s->fillSquare(new Point(0, w->getWindowHeight() - kenarYukseklik), w->getWindowWidth(), kenarYukseklik, pixelColor);

	for (int i = 0; i < 14; i++) {
		s->fillSquare(new Point(w->getWindowWidth() / 2, 20 + i * (topBoyut + 10)), topBoyut, topBoyut, pixelColor);
	}
}

void PongGame::setGameSpeed(gameLevel level) {
	if (level == 0) {
		this->gameSpeed = 40;
	}
	else if (level == 1) {
		this->gameSpeed = 60;
	}
	else if (level == 2) {
		this->gameSpeed = 150;
	}
	else {
		// hatali tuslama
	}
}

void PongGame::setBgColor(BgColors color) {
	bgColor = c->colorsValue[color];
	std::string fullStr = "color ";
	fullStr.append(std::to_string(color));
	fullStr.append("a");
	const char* v = fullStr.c_str();
	system(v);
}
void PongGame::setPixelColor(COLORREF color) {
	pixelColor = color;
}

void PongGame::hideBall() {
	s->fillSquare(new Point(x, y), topBoyut, topBoyut, bgColor);
}

void PongGame::hideRacket() {
	s->fillSquare(new Point(raketX, raketY), raketGenislik, raketUzunluk, bgColor);
}

void PongGame::hideOtoRacket() {
	s->fillSquare(new Point(otoRaketX, otoRaketY), raketGenislik, raketUzunluk, bgColor);
}

void PongGame::play() {
	while (true) {

		// oyun hareketleri
		s->fillSquare(new Point(raketX, raketY), 10, raketUzunluk, pixelColor); // ilk raket
		s->fillSquare(new Point(otoRaketX, otoRaketY), 10, raketUzunluk, pixelColor); //2.raket

		// top hareketleri
		s->fillSquare(new Point(x, y), topBoyut, topBoyut, pixelColor);//top
		Sleep(1000/gameSpeed); // 60 fps degerinde calissin
		hideBall();

		// raket hareketleri

		if (_kbhit()) { // tiklanma varsa calissin
			tus = (char)_getch();

			if (tus == 'w' && raketY >= kenarYukseklik) { // yukari dogru hareket raket1
				hideRacket();
				raketY = raketY - raketArttirmaDegeri;
				s->fillSquare(new Point(raketX, raketY), raketGenislik, raketUzunluk, pixelColor);
			}
			if (tus == 's' && raketY <= w->getWindowHeight() - (kenarYukseklik + raketUzunluk)) { // asagi dogru hareket raket1
				hideRacket();
				raketY = raketY + raketArttirmaDegeri;
				s->fillSquare(new Point(raketX, raketY), raketGenislik, raketUzunluk, pixelColor);
			}
		}

		if (y >= otoRaketY) {
			hideOtoRacket();
			otoRaketY = otoRaketY + otoDy;
			s->fillSquare(new Point(otoRaketX, otoRaketY), raketGenislik, raketUzunluk, pixelColor);
		}
		else if (y <= otoRaketY) {
			hideOtoRacket();
			otoRaketY = otoRaketY - otoDy;
			s->fillSquare(new Point(otoRaketX, otoRaketY), raketGenislik, raketUzunluk, pixelColor);
		}
		else {
			otoRaketY = otoRaketY;
		}


		// arttirma kisimlari

		if (tus != ' ') {
			tus = ' ';
		}

		if ((x >= otoRaketX && y >= (otoRaketY - topBoyut) && y <= (otoRaketY + raketUzunluk)) ||
			((x <= raketX) && (y >= (raketY - topBoyut) && y <= (raketY + raketUzunluk)))
			) {
			dx = dx * -1;
		}
		if (x<0 || x>w->getWindowWidth()) {
			std::cout << (char)7;
			std::cout << "kaybettiniz";
			x = w->getWindowWidth() / 2;
			y = w->getWindowHeight() / 2;
			raketX = 20;
			raketY = w->getWindowHeight() / 2 - 25;
			otoRaketX = w->getWindowWidth() - 20 - 10;
			otoRaketY = w->getWindowHeight() / 2 - 30;
			Sleep(1000);
		}

		if (y >= (w->getWindowHeight() - kenarYukseklik - 20) || y <= (0 + kenarYukseklik)) {
			dy = dy * -1;
		}
		x = x + dx;
		y += dy;

	}
}

