#pragma once
#include <Windows.h>
#include "GameManager.h"
#include <conio.h>

enum ConsoleColor {
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	YELLOW = 6,
	WHITE = 7,
	GRAY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	LIGHT_MAGENTA = 13,
	LIGHT_YELLOW = 14,
	BRIGHT_WHITE = 15
};
class ShowMainMenu {
public:
	void Initialize();
	void gotoXY(int x, int y);
	void setColor(int textColor, int bgColor = 0);
	int arrowMenu();
	void showGameDescription();
private:
	void drawLogo();
	void drawMenuBox(int x, int y, int width, int height);
	void setConsoleSize(int width, int height);
};

