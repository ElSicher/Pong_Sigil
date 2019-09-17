#include "PantallaGameOver.h"
void p1Winner(GAMESTATE &state, bool &winnerP1)
{
	if (slGetKey(SL_KEY_ENTER))
	{
		state = game;
		winnerP1 = false;
	}
	if (slGetKey(32))
	{
		state = menu;
		winnerP1 = false;
	}
}
void drawWinner1(int screenWidth, int screenHeight)
{
	slText(screenWidth / 2, 500, "PLAYER 1 WINS!");
	slText(screenWidth / 2, screenHeight / 2, "Press ENTER to PLAY Again");
	slText(screenWidth / 2, 310, "Press SPACE to get back to the MENU");
	slText(screenWidth / 2, 250, "Press SCAPE to EXIT");
}