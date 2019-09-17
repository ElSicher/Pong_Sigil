#include "GAMESTATE.h"
#include "Paletas.h";
#include "Pelotas.h"
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
		state = menu;

		//players
		player1.x = 100;
		player1.y = 360;
		player1.height = 150;
		player1.width = 20;
		player1.red = 255;
		player1.blue = 0;
		player1.green = 0;

		player2.x = 1180;
		player2.y = 360;
		player2.height = 150;
		player2.width = 20;
		player2.red = 0;
		player2.blue = 255;
		player2.green = 0;


		//ball
		ball.x = 640;
		ball.y = 360;

		//game
		slWindow(screenWidth, screenHeight, "PONG v1.0", false);
		slSetFont(slLoadFont("ttf/whitrabt.ttf"), 24);
		slSetTextAlign(SL_ALIGN_CENTER);
		while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
		{
			if (state == menu)
			{
				if (slGetKey(SL_KEY_ENTER))	state = game;
				if (slGetKey(32)) state = gameAI;

				slText(screenWidth / 2, 500, "PONG");
				slText(screenWidth / 2, 420, "Press ENTER to PLAY");
				slText(screenWidth / 2, screenHeight/2, "Press SPACE to Play against AI");
				slText(screenWidth / 2, 300, "Press SCAPE to EXIT");


			}

			if (state == game)
			{
				//init
				if (initStart == true)
				{
					p1ColWithBall = true;
					p2ColWithBall = true;
					initStart = false;
				}
				//input

				if (slGetKey('W')) player1.y += 8;
				if (slGetKey('S')) player1.y -= 8;
				if (slGetKey(SL_KEY_UP)) player2.y += 8;
				if (slGetKey(SL_KEY_DOWN)) player2.y -= 8;

				if (slGetKey(32)) start = true;		//space = 32 in ASCII

				if (start == true)
				{
					ball.x += ball.ballSpeedX;
					ball.y += ball.ballSpeedY;

				}


				//update

				//collisions
				if (p2ColWithBall && (ball.x + ball.radius) >= (player2.x - player2.width / 2) && (ball.x + ball.radius) <= (player2.x + player2.width / 2) && (ball.y >= (player2.y - player2.height / 2)) && (ball.y <= (player2.y + player2.height / 2)))
				{
					ball.ballSpeedX *= -1.0f;
					p2ColWithBall = false;
					p1ColWithBall = true;
					colorP2 = true;
					colorP1 = false;
				}
				if (p1ColWithBall && (ball.x - ball.radius) <= (player1.x + player1.width / 2) && (ball.x + ball.radius) >= (player1.x - player1.width / 2) && (ball.y >= (player1.y - player1.height / 2)) && (ball.y <= (player1.y + player1.height / 2)))
				{
					ball.ballSpeedX *= -1.0f;
					p1ColWithBall = false;
					p2ColWithBall = true;
					colorP1 = true;
					colorP2 = false;
				}
				if (player1.y - player1.height / 2 <= 0)
				{
					player1.y = player1.height / 2;
				}
				else if (player1.y + player1.height / 2 >= screenHeight)
				{
					player1.y = 720 - player1.height / 2;
				}
				if (player2.y - player2.height / 2 <= 0)
				{
					player2.y = player2.height / 2;
				}
				else if (player2.y + player2.height / 2 >= screenHeight)
				{
					player2.y = 720 - player2.height / 2;
				}
				if (ball.y + ball.radius >= screenHeight)
				{
					ball.ballSpeedY *= -1.0f;
				}
				if (ball.y - ball.radius <= 0)
				{
					ball.ballSpeedY *= -1.0f;
				}

				//rules
				if (ball.x + ball.radius >= screenWidth)
				{
					ball.x = screenWidth / 2;
					ball.y = screenHeight / 2;
					start = false;
					p1ColWithBall = true;
					p2ColWithBall = true;
					initStart = true;
					scoreP1++;
				}
				if (ball.x - ball.radius <= 0)
				{
					ball.x = screenWidth / 2;
					ball.y = screenHeight / 2;
					start = false;
					p1ColWithBall = true;
					p2ColWithBall = true;
					initStart = true;
					scoreP2++;
				}
				if (scoreP1 == 3)
				{
					winnerP1 = true;
					state = gameOver;
					scoreP1 = 0;
					scoreP2 = 0;
					initStart = false;
				}
				if (scoreP2 == 3)
				{
					winnerP2 = true;
					state = gameOver;
					scoreP1 = 0;
					scoreP2 = 0;
					initStart = false;
				}

				//draw

				slSetFontSize(24);
				string score1 = "Player 1: " + to_string(scoreP1);
				string score2 = "Player 2: " + to_string(scoreP2);
				slText(100, 690, score1.c_str());
				slText(1180, 690, score2.c_str());


				if (colorP2 == true)
				{
					slSetForeColor(player2.red, player2.green, player2.blue, 1);
					slCircleFill(ball.x, ball.y, ball.radius, ball.vert);
					slSetForeColor(255, 255, 255, 1);
				}
				if (colorP1 == true)
				{
					slSetForeColor(player1.red, player1.green, player1.blue, 1);
					slCircleFill(ball.x, ball.y, ball.radius, ball.vert);
					slSetForeColor(255, 255, 255, 1);
				}

				slCircleFill(ball.x, ball.y, ball.radius, ball.vert);


				slSetForeColor(player1.red, player1.green, player1.blue, 1);
				slRectangleFill(player1.x, player1.y, player1.width, player1.height);
				slSetForeColor(255, 255, 255, 1);

				slSetForeColor(player2.red, player2.green, player2.blue, 1);
				slRectangleFill(player2.x, player2.y, player2.width, player2.height);
				slSetForeColor(255, 255, 255, 1);
			}

			if (state == gameAI)
			{
				//init
				if (initStart == true)
				{
					p1ColWithBall = true;
					p2ColWithBall = true;
					initStart = false;
				}
				//input

				if (slGetKey('W')) player1.y += 8;
				if (slGetKey('S')) player1.y -= 8;
					
				player2.y = ball.y;

				if (slGetKey(32)) start = true;		//space = 32 in ASCII

				if (start == true)
				{
					ball.x += ball.ballSpeedX;
					ball.y += ball.ballSpeedY;

				}

				//update

				//collisions
				if (p2ColWithBall && (ball.x + ball.radius) >= (player2.x - player2.width / 2) && (ball.x + ball.radius) <= (player2.x + player2.width / 2) && (ball.y >= (player2.y - player2.height / 2)) && (ball.y <= (player2.y + player2.height / 2)))
				{
					ball.ballSpeedX *= -1.0f;
					p2ColWithBall = false;
					p1ColWithBall = true;
					colorP2 = true;
					colorP1 = false;
				}
				if (p1ColWithBall && (ball.x - ball.radius) <= (player1.x + player1.width / 2) && (ball.x + ball.radius) >= (player1.x - player1.width / 2) && (ball.y >= (player1.y - player1.height / 2)) && (ball.y <= (player1.y + player1.height / 2)))
				{
					ball.ballSpeedX *= -1.0f;
					p1ColWithBall = false;
					p2ColWithBall = true;
					colorP1 = true;
					colorP2 = false;
				}
				if (player1.y - player1.height / 2 <= 0)
				{
					player1.y = player1.height / 2;
				}
				else if (player1.y + player1.height / 2 >= screenHeight)
				{
					player1.y = 720 - player1.height / 2;
				}
				if (player2.y - player2.height / 2 <= 0)
				{
					player2.y = player2.height / 2;
				}
				else if (player2.y + player2.height / 2 >= screenHeight)
				{
					player2.y = 720 - player2.height / 2;
				}
				if (ball.y + ball.radius >= screenHeight)
				{
					ball.ballSpeedY *= -1.0f;
				}
				if (ball.y - ball.radius <= 0)
				{
					ball.ballSpeedY *= -1.0f;
				}

				//rules
				if (ball.x + ball.radius >= screenWidth)
				{
					ball.x = screenWidth / 2;
					ball.y = screenHeight / 2;
					start = false;
					p1ColWithBall = true;
					p2ColWithBall = true;
					initStart = true;
					scoreP1++;
				}
				if (ball.x - ball.radius <= 0)
				{
					ball.x = screenWidth / 2;
					ball.y = screenHeight / 2;
					start = false;
					p1ColWithBall = true;
					p2ColWithBall = true;
					initStart = true;
					scoreAI++;
				}
				if (scoreP1 == 3)
				{
					winnerP1 = true;
					state = gameOver;
					scoreP1 = 0;
					scoreP2 = 0;
					initStart = false;
				}
				if (scoreP2 == 3)
				{
					winnerP2 = true;
					state = gameOver;
					scoreP1 = 0;
					scoreP2 = 0;
					initStart = false;
				}
				if (scoreAI == 3)
				{
					winnerAI = true;
					state = gameOver;
					scoreAI = 0;
					scoreP1 = 0;
					initStart = false;
				}

				//draw

				slSetFontSize(24);
				string score1 = "Player 1: " + to_string(scoreP1);
				string score2 = "AI: " + to_string(scoreAI);
				slText(100, 690, score1.c_str());
				slText(1180, 690, score2.c_str());


				if (colorP2 == true)
				{
					slSetForeColor(player2.red, player2.green, player2.blue, 1);
					slCircleFill(ball.x, ball.y, ball.radius, ball.vert);
					slSetForeColor(255, 255, 255, 1);
				}
				if (colorP1 == true)
				{
					slSetForeColor(player1.red, player1.green, player1.blue, 1);
					slCircleFill(ball.x, ball.y, ball.radius, ball.vert);
					slSetForeColor(255, 255, 255, 1);
				}

				slCircleFill(ball.x, ball.y, ball.radius, ball.vert);


				slSetForeColor(player1.red, player1.green, player1.blue, 1);
				slRectangleFill(player1.x, player1.y, player1.width, player1.height);
				slSetForeColor(255, 255, 255, 1);

				slSetForeColor(player2.red, player2.green, player2.blue, 1);
				slRectangleFill(player2.x, player2.y, player2.width, player2.height);
				slSetForeColor(255, 255, 255, 1);
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
