#include "GAMESTATE.h"
#include "Paletas.h"
#include "Pelotas.h"

void initMatch(bool &initStart, bool &p1ColWithBall, bool &p2ColWithBall)
{
	if (initStart == true)
	{
		p1ColWithBall = true;
		p2ColWithBall = true;
		initStart = false;
	}
}
void startGame(bool &start)
{
	if (slGetKey(32)) start = true;		//space = 32 in ASCII

	if (start == true)
	{
		ball.x += ball.ballSpeedX;
		ball.y += ball.ballSpeedY;

	}
}
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
void rulesAI(int screenHeight, int screenWidth, bool &p2ColWithBall, bool &p1ColWithBall, int &scoreP1, int &scoreAI, bool &start, bool &initStart, bool &winnerP1, bool &winnerAI)
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
		scoreAI++;
	}
	if (scoreP1 == 3)
	{
		winnerP1 = true;
		state = gameOver;
		scoreP1 = 0;
		scoreAI = 0;
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
}
void drawGame(bool &colorP1, bool &colorP2, int scoreP1, int scoreP2)
{
	slSetFontSize(24);
	string score1 = "Player 1: " + to_string(scoreP1);
	string score2 = "Player 2: " + to_string(scoreP2);
	slText(100, 690, score1.c_str());
	slText(1180, 690, score2.c_str());

	slCircleFill(ball.x, ball.y, ball.radius, ball.vert);
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


	slSetForeColor(player1.red, player1.green, player1.blue, 1);
	slRectangleFill(player1.x, player1.y, player1.width, player1.height);
	slSetForeColor(255, 255, 255, 1);

	slSetForeColor(player2.red, player2.green, player2.blue, 1);
	slRectangleFill(player2.x, player2.y, player2.width, player2.height);
	slSetForeColor(255, 255, 255, 1);
}
void drawGameAI(bool &colorP1, bool &colorP2, int scoreP1, int scoreAI)
{
	
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
void gameLoop(GAMESTATE &state, bool &initStart, bool &start, bool &p1ColWithBall, bool &p2ColWithBall, bool &colorP1, bool &colorP2, int &scoreP1, int &scoreP2, int &scoreAI, bool &winnerP1, bool &winnerAI, bool &winnerP2, int screenWidth, int screenHeight)
{
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
}