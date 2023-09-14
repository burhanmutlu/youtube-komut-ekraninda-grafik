#pragma once

#include "Window.h"
#include "Square.h"
#include "Point.h"
#include "Color.h"
#include <stdlib.h>
#include <conio.h>
#include <string>

enum gameLevel {
	easy,
	medium,
	hard
};


class PongGame
{
public:
	PongGame();
	void drawScene();
	void setGameSpeed(gameLevel level);
	void setBgColor(BgColors color);
	void setPixelColor(COLORREF color);
	void play();
private:
	void hideBall();
	void hideRacket();
	void hideOtoRacket();

	Window* w;
	Square* s;
	Color* c;
	int kenarYukseklik;
	int x;
	int y;
	int dx;
	int dy;
	int raketX;
	int raketY;
	int raketArttirmaDegeri;
	int raketUzunluk;
	int raketGenislik;
	char tus;
	int otoRaketX;
	int otoRaketY;
	int otoDy;
	int topBoyut;
	int gameSpeed;
	COLORREF bgColor;
	COLORREF pixelColor;

};

