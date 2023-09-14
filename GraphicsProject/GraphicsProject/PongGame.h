#pragma once

#include "Window.h"
#include "Square.h"
#include "Point.h"
#include "Color.h"
#include "Line.h"
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
	void setGameSpeed(gameLevel level);
	void setBgColor(BgColors color);
	void setPixelColor(COLORREF color);
	void play();
private:
	void drawScene();
	void drawBall();
	void hideBall();
	void hideRacket();
	void hideOtoRacket();

	Window* w;
	Square* s;
	Color* c;
	Line* line;

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
	bool isStart;
	int firstPlayerScore;
	int secondPlayerScore;
	COLORREF bgColor;
	COLORREF pixelColor;

};

