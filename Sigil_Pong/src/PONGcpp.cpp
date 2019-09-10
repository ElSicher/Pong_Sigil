#include "sl.h"
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
	slWindow(1280, 720, "PONG v1.0", false);
	slSetTextAlign(SL_ALIGN_CENTER);

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{ 
		//inputs
		if (slGetKey('W')) player1.y += 8;	
		if (slGetKey('S')) player1.y -= 8;
		if (slGetKey(SL_KEY_UP)) player2.y += 8;
		if (slGetKey(SL_KEY_DOWN)) player2.y -= 8;
		
		//drawings
		slRectangleFill(player1.x, player1.y, player1.width, player1.height);
		slRectangleFill(player2.x, player2.y, player2.width, player2.height);
		slCircleFill(ball.x, ball.y, ball.radius, ball.vert);

		ball.x += ball.ballSpeedX;
		if ((ball.x + ball.radius) >= ((player2.x - player2.width /2)) && (ball.y + ball.radius)>=(player2.y - player2.height/2))
		{
			ball.ballSpeedX *= -1.0f; 
		}
		if ((ball.x - ball.radius) <= ((player1.x + player1.width / 2)))
		{
			ball.ballSpeedX *= -1.0f;
		}
		

		
	
		slRender();
	}
	slClose();

}
