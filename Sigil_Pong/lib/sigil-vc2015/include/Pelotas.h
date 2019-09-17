#pragma once
struct Ball {
	float ballSpeedX = 9.0f;
	float ballSpeedY = 8.0f;
	int x;
	int y;
	int radius = 15;
	int vert = 40;
};
extern Ball ball;