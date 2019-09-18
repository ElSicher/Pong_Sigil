#pragma once
#include "Paletas.h"


//init
void initMatch(bool &initStart, bool &p1ColWithBall, bool &p2ColWithBall);
void startGame(bool &start);
//update
void input();
void inputAI();
void collisions(int screenHeight, int screenWidth, bool &p2ColWithBall, bool &p1ColWithBall, bool &colorP1, bool &colorP2);
void rules(int screenHeight, int screenWidth, bool &p2ColWithBall, bool &p1ColWithBall, int &scoreP1, int &scoreP2, bool &start, bool &initStart, bool &winnerP1, bool &winnerP2);
void rulesAI(int screenHeight, int screenWidth, bool &p2ColWithBall, bool &p1ColWithBall, int &scoreP1, int &scoreAI, bool &start, bool &initStart, bool &winnerP1, bool &winnerAI);
//draw
void drawGame(bool &colorP1, bool &colorP2, int scoreP1, int scoreP2);
void drawGameAI(bool &colorP1, bool &colorP2, int scoreP1, int scoreAI);

void gameLoop(GAMESTATE &state, bool &initStart, bool &start, bool &p1ColWithBall, bool &p2ColWithBall, bool &colorP1, bool &colorP2, int &scoreP1, int &scoreP2, int &scoreAI, bool &winnerP1, bool &winnerAI, bool &winnerP2, int screenWidth, int screenHeight);