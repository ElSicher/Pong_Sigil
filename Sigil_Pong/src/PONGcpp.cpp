#include "GAMESTATE.h"
#include "Paletas.h";
#include "Pelotas.h"
#include "Gameplay.h"
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

		//ball
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
				//init
				initMatch(initStart, p1ColWithBall, p2ColWithBall);

				//update
				startGame(start);
				
				input();

				collisions(screenHeight, screenWidth, p2ColWithBall, p1ColWithBall, colorP1, colorP2);

				rules(screenHeight, screenWidth, p2ColWithBall, p1ColWithBall, scoreP1, scoreP2, start, initStart, winnerP1, winnerP2);
				
				//draw
				drawGame(colorP1, colorP2, scoreP1, scoreP2);
				
			}

			if (state == gameAI)
			{
				//init
				initMatch(initStart, p1ColWithBall, p2ColWithBall);
				//input

				inputAI();
				
				startGame(start);
				

				//update

				//collisions
				collisions(screenHeight, screenWidth, p2ColWithBall, p1ColWithBall, colorP1, colorP2);
			
				//rules
				rulesAI(screenHeight, screenWidth, p2ColWithBall, p1ColWithBall, scoreP1, scoreAI, start, initStart, winnerP1, winnerAI);

				//draw
				drawGameAI(colorP1, colorP2, scoreP1, scoreAI);
			}

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

			if(state == gameOver && winnerAI == true)
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

			slRender();
		}
	slClose();

}
