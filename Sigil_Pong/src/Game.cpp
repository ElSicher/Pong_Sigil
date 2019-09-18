#include "Game.h"
GAMESTATE state;

Players player1;
Players player2;
Ball ball;

bool p1ColWithBall = true;
bool p2ColWithBall = true;
bool start = false;
bool initStart = true;
bool winnerP1 = false;
bool winnerP2 = false;
bool winnerAI = false;
bool colorP1 = false;
bool colorP2 = false;

int scoreP1 = 0;
int scoreP2 = 0;
int scoreAI = 0;