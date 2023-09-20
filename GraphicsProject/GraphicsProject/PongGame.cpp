#include "PongGame.h"

PongGame::PongGame() {
	w = new Window();
	s = new Square();
	c = new Color();
	line = new Line();	

	kenarYukseklik = w->getWindowHeight() / 30;
	x = w->getWindowWidth() / 2;
	y = w->getWindowHeight() / 2;
	dx = 6;
	dy = 6;
	raketX = 20;
	raketY = w->getWindowHeight() / 2 - 25;
	raketArttirmaDegeri = 50;
	raketUzunluk = 50;
	raketGenislik = 10;
	tus = ' ';
	otoRaketX = w->getWindowWidth() - 20 - 10;
	otoRaketY = w->getWindowHeight() / 2 - 30;
	otoDy = 5;
	topBoyut = 15;
	gameSpeed = 60;
	isStart = false;
	firstPlayerScore = 0;
	secondPlayerScore = 0;
	bgColor = BLACK;
	pixelColor = WHITE;
}

void PongGame::drawScene() {
	
	if (isStart == false) {
		s->fillSquare(new Point(0, 0), w->getWindowWidth(), w->getWindowHeight() / 30, pixelColor); // ust kenar
		s->fillSquare(new Point(0, w->getWindowHeight() - kenarYukseklik), w->getWindowWidth(), kenarYukseklik, pixelColor);//alt kenar
		
		s->fillSquare(new Point(raketX, raketY), raketGenislik, raketUzunluk, pixelColor); //raket1
		s->fillSquare(new Point(otoRaketX, otoRaketY), raketGenislik, raketUzunluk, pixelColor);//raket2
		isStart = true;
	}
	//burasý silindigi icin
	int x1 = w->getWindowWidth() / 2;
	int y1 = 0;
	int x2 = w->getWindowWidth() / 2;
	int y2 = w->getWindowHeight();

	line->setColor(pixelColor);
	line->drawLine(x1, y1, x2, y2);
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
	fullStr.append("f");
	const char* v = fullStr.c_str();
	system(v);
}

void PongGame::setPixelColor(COLORREF color) {
	pixelColor = color;
}

void PongGame::drawBall() {
	s->fillSquare(new Point(x, y), topBoyut, topBoyut, pixelColor);
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

	drawScene();
	while (true) {
		drawScene();
		drawBall();
		
		if (_kbhit()) { // tiklanma varsa calissin
			tus = (char)_getch();
			hideRacket();
			if (tus == 'w' && raketY >= kenarYukseklik) { // yukari dogru hareket raket1
				raketY = raketY - raketArttirmaDegeri;
				s->fillSquare(new Point(raketX, raketY), raketGenislik, raketUzunluk, pixelColor);
			}
			if (tus == 's' && raketY <= w->getWindowHeight() - (kenarYukseklik + raketUzunluk)) { // asagi dogru hareket raket1
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


		//top yon degistirme
		if ((x >= otoRaketX && y >= (otoRaketY - topBoyut) && y <= (otoRaketY + raketUzunluk)) ||
			((x <= raketX) && (y >= (raketY - topBoyut) && y <= (raketY + raketUzunluk)))
			) {
			dx = dx * -1;
		}
		if (y >= (w->getWindowHeight() - kenarYukseklik - 20) || y <= (0 + kenarYukseklik)) {
			dy = dy * -1;
		}


		Sleep(1000 / gameSpeed);
		hideBall();
		x = x + dx;
		y += dy;

		//puan kazanma ve oyunun yeniden baslamasi
		if (x<0 || x>w->getWindowWidth()) {
			if (x < 0) {
				secondPlayerScore += 1;
			}
			else if (x > w->getWindowWidth()) {
				firstPlayerScore += 1;
			}
			
			//puana gore oyunu bitirme
			if ((secondPlayerScore + firstPlayerScore) == 5) {
				std::cout << (char)7;
				system("cls");
				std::cout << "Skor: " << firstPlayerScore << " - " << secondPlayerScore;
				std::cout << "\nTekrar oynamak icin bir tusa basiniz.";
				
				
				if ( _getch() ) {
					system("cls");
					firstPlayerScore = 0;
					secondPlayerScore = 0;
					isStart = false;
					x = w->getWindowWidth() / 2;
					y = kenarYukseklik + rand() % w->getWindowHeight();
					raketX = 20;
					raketY = w->getWindowHeight() / 2 - 25;
					otoRaketX = w->getWindowWidth() - 20 - 10;
					otoRaketY = w->getWindowHeight() / 2 - 30;
					std::cout << "Oyun Basliyor...";
					Sleep(1000);
					system("cls");
					this->play();
				}	
	
			} else {
				Sleep(600);
				hideRacket();
				hideOtoRacket();
				isStart = false;
				x = w->getWindowWidth() / 2;
				y = kenarYukseklik + rand() % (w->getWindowHeight()-2*kenarYukseklik);
				raketX = 20;
				raketY = w->getWindowHeight() / 2 - 25;
				otoRaketX = w->getWindowWidth() - 20 - 10;
				otoRaketY = w->getWindowHeight() / 2 - 30;
			}
			
		}

	}
}
