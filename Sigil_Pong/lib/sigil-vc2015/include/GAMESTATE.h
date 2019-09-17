#pragma once
#include "sl.h"
#include <string>
using namespace std;
enum GAMESTATE {
	menu,
	game,
	gameAI,
	gameOver
};
extern GAMESTATE state;

void mainMenu(GAMESTATE &state, int screenWidth, int screenHeight);