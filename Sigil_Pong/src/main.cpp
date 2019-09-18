#include "GAMESTATE.h"
#include "Paletas.h";
#include "Pelotas.h"
#include "PantallaGameplay.h"
#include "PantallaGameOver.h"
#include "Game.h"

using namespace std;
#define screenHeight 720
#define screenWidth 1280

void main()
{
		
		//players
		initPaleta();

		initPelota();

		//game
		slWindow(screenWidth, screenHeight, "PONG v1.0", false);
		slSetFont(slLoadFont("ttf/whitrabt.ttf"), 24);
		slSetTextAlign(SL_ALIGN_CENTER);
		while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
		{
			mainMenu(state, screenWidth, screenHeight);

			gameLoop(state, initStart, start, p1ColWithBall, p2ColWithBall, colorP1, colorP2, scoreP1, scoreP2, scoreAI,winnerP1, winnerAI, winnerP2, screenWidth, screenHeight);

			gameOverScreen(state, winnerP1, winnerP2, winnerAI, screenWidth, screenHeight);
			
			slRender();
		}
	slClose();

}
