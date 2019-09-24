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

void init() 
{
	initPaleta();

	initPelota();

	slWindow(screenWidth, screenHeight, "PONG v1.0", false);
	slSetFont(slLoadFont("ttf/whitrabt.ttf"), 24);
	slSetTextAlign(SL_ALIGN_CENTER);
}
void update()
{
	mainMenu(state, screenWidth, screenHeight);

	gameLoop(state, initStart, start, p1ColWithBall, p2ColWithBall, colorP1, colorP2, scoreP1, scoreP2, scoreAI, winnerP1, winnerAI, winnerP2, screenWidth, screenHeight);

	gameOverScreen(state, winnerP1, winnerP2, winnerAI, screenWidth, screenHeight);

}
void draw()
{
	slRender();
}

void executeGame()
{
	init();
	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
		update();
		draw();
	}
	slClose();
}