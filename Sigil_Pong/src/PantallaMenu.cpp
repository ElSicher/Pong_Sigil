#include "GAMESTATE.h"
void mainMenu(GAMESTATE &state, int screenWidth, int screenHeight)
{
	if (state == menu)
	{
		if (slGetKey(SL_KEY_ENTER))	state = game;
		if (slGetKey(32)) state = gameAI;

		slText(screenWidth / 2, 500, "PONG");
		slText(screenWidth / 2, 420, "Press ENTER to PLAY");
		slText(screenWidth / 2, screenHeight / 2, "Press SPACE to Play against AI");
		slText(screenWidth / 2, 300, "Press SCAPE to EXIT");


	}
}