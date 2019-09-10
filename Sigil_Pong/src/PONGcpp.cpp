#include "sl.h"
#define screenHeight 720
#define screenWidth 1280
enum GAMESTATE {
	menu,
	gamePvP,
	gameAI,
	end
}state;
struct Vector2
{
	int x;
	int y;
};
struct Players {
	int width;
	int height;
	int x;
	int y;
};
struct Ball {
	float ballSpeedX = 7.0f;
	float ballSpeedY = 6.0f;
	int x;
	int y;
	int radius = 15;
	int vert = 40;
};

Players player1;
Players player2;
Ball ball;
bool p1ColWithBall = true;
bool p2ColWithBall = true;
bool start = false;
bool initStart = true;

void main()
{
	//players
	player1.x = 100;
	player1.y = 360;
	player1.height = 150;
	player1.width = 20;

	player2.x = 1180;
	player2.y = 360;
	player2.height = 150;
	player2.width = 20;

	//ball
	ball.x = 640;
	ball.y = 360;

	//game
	slWindow(screenWidth, screenHeight, "PONG v1.0", false);
	slSetTextAlign(SL_ALIGN_CENTER);

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{ 
		//init
		if (initStart == true)
		{
			p1ColWithBall = true;
			p2ColWithBall = true;
			initStart = false;
		}
		//inputs
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
		
		//drawings
		slRectangleFill(player1.x, player1.y, player1.width, player1.height);
		slRectangleFill(player2.x, player2.y, player2.width, player2.height);
		slCircleFill(ball.x, ball.y, ball.radius, ball.vert);

		
		//collisions
		if (p2ColWithBall && (ball.x + ball.radius) >= (player2.x - player2.width /2) && (ball.x + ball.radius) <= (player2.x + player2.width / 2) && (ball.y >=(player2.y-player2.height/2)) && (ball.y <= (player2.y + player2.height / 2)))
		{
			ball.ballSpeedX *= -1.0f; 
			p2ColWithBall = false;
			p1ColWithBall = true;
		}
		if (p1ColWithBall&&(ball.x - ball.radius) <= (player1.x + player1.width / 2) && (ball.x + ball.radius) >= (player1.x - player1.width/2) && (ball.y >= (player1.y - player1.height/2)) && (ball.y <= (player1.y + player1.height /2)))
		{
			ball.ballSpeedX *= -1.0f;
			p1ColWithBall = false;
			p2ColWithBall = true;
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
		}
		if (ball.x - ball.radius <= 0)
		{
			ball.x = screenWidth / 2;
			ball.y = screenHeight / 2;
			start = false;
			p1ColWithBall = true;
			p2ColWithBall = true;
			initStart = true;
		}

	
		slRender();
	}
	slClose();

}
