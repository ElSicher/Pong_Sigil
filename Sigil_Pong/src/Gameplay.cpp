#include "GAMESTATE.h"
#include "Paletas.h"
#include "Pelotas.h"


void input() 
{
	if (slGetKey('W')) player1.y += 8;
	if (slGetKey('S')) player1.y -= 8;
	if (slGetKey(SL_KEY_UP)) player2.y += 8;
	if (slGetKey(SL_KEY_DOWN)) player2.y -= 8;
}
void inputAI()
{
	if (slGetKey('W')) player1.y += 8;
	if (slGetKey('S')) player1.y -= 8;

	player2.y = ball.y;
}
void collisions(int screenHeight, int screenWidth, bool &p2ColWithBall, bool &p1ColWithBall, bool &colorP1, bool &colorP2)
{
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

}
void rules(int screenHeight, int screenWidth, bool &p2ColWithBall, bool &p1ColWithBall, int &scoreP1, int &scoreP2, bool &start, bool &initStart, bool &winnerP1, bool &winnerP2)
{
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
}