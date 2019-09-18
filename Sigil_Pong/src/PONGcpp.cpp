#include "GAMESTATE.h"
#include "Paletas.h";
#include "Pelotas.h"
#include "PantallaGameplay.h"
#include "PantallaGameOver.h"
using namespace std;
#define screenHeight 720
#define screenWidth 1280

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

			if (state == game)
			{
				initMatch(initStart, p1ColWithBall, p2ColWithBall);

				//update
				startGame(start);
				
				input();

				collisions(screenHeight, screenWidth, p2ColWithBall, p1ColWithBall, colorP1, colorP2);

				rules(screenHeight, screenWidth, p2ColWithBall, p1ColWithBall, scoreP1, scoreP2, start, initStart, winnerP1, winnerP2);

				drawGame(colorP1, colorP2, scoreP1, scoreP2);
			}

			if (state == gameAI)
			{
				initMatch(initStart, p1ColWithBall, p2ColWithBall);
			
				//update
				inputAI();
				
				startGame(start);

				collisions(screenHeight, screenWidth, p2ColWithBall, p1ColWithBall, colorP1, colorP2);
			
				rulesAI(screenHeight, screenWidth, p2ColWithBall, p1ColWithBall, scoreP1, scoreAI, start, initStart, winnerP1, winnerAI);

				drawGameAI(colorP1, colorP2, scoreP1, scoreAI);
			}

			gameOverScreen(state, winnerP1, winnerP2, winnerAI, screenWidth, screenHeight);
			
			slRender();
		}
	slClose();

}
