#pragma once
#include "gameplayScreen.h"
#include "gameOverScreen.h"
#include "ball.h"
#include "Paddle.h"
#include "menuScreen.h"
#define screenHeight 720
#define screenWidth 1280
using namespace std;

extern bool p1ColWithBall;
extern bool p2ColWithBall;
extern bool start;
extern bool initStart;
extern bool winnerP1;
extern bool winnerP2;
extern bool winnerAI;
extern bool colorP1;
extern bool colorP2;

extern int scoreP1;
extern int scoreP2;
extern int scoreAI;

void init();
void update();
void draw();
void executeGame();