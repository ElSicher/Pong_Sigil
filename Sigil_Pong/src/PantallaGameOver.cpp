#include "PantallaGameOver.h"

void gameOverScreen(GAMESTATE &state, bool &winnerP1, bool &winnerP2, bool &winnerAI, int screenWidth, int screenHeight)
{
	if (state == gameOver && winnerP1 == true)
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

		slText(screenWidth / 2, 500, "PLAYER 1 WINS!");
		slText(screenWidth / 2, screenHeight / 2, "Press ENTER to PLAY Again");
		slText(screenWidth / 2, 310, "Press SPACE to get back to the MENU");
		slText(screenWidth / 2, 250, "Press SCAPE to EXIT");
	}

	if (state == gameOver && winnerP2 == true)
	{
		if (slGetKey(SL_KEY_ENTER))
		{
			state = game;
			winnerP2 = false;
		}
		if (slGetKey(32))
		{
			state = menu;
			winnerP2 = false;
		}
		slText(screenWidth / 2, 500, "PLAYER 2 WINS!");
		slText(screenWidth / 2, screenHeight / 2, "Press ENTER to PLAY Again");
		slText(screenWidth / 2, 310, "Press SPACE to get back to the MENU");
		slText(screenWidth / 2, 250, "Press SCAPE to EXIT");
	}

	if (state == gameOver && winnerAI == true)
	{
		if (slGetKey(SL_KEY_ENTER))
		{
			state = gameAI;
			winnerAI = false;
		}
		if (slGetKey(32))
		{
			state = menu;
			winnerAI = false;
		}
		slText(screenWidth / 2, 500, "The AI WINS!");
		slText(screenWidth / 2, screenHeight / 2, "Press ENTER to PLAY Again");
		slText(screenWidth / 2, 310, "Press SPACE to get back to the MENU");
		slText(screenWidth / 2, 250, "Press SCAPE to EXIT");
	}
}