#pragma once
#include "Paletas.h"
void input();
void inputAI();
void collisions(int screenHeight, int screenWidth, bool &p2ColWithBall, bool &p1ColWithBall, bool &colorP1, bool &colorP2);
void rules(int screenHeight, int screenWidth, bool &p2ColWithBall, bool &p1ColWithBall, int &scoreP1, int &scoreP2, bool &start, bool &initStart, bool &winnerP1, bool &winnerP2);