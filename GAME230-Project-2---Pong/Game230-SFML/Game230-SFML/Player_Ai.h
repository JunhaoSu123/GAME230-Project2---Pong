#pragma once
#include"Paddle.h"
#include"Ball_Ai.h"
#include"Ball.h"

class player_ai : public paddle {
public:
	player_ai(int playerNumber);
	void SetBall(ball_ai* ballObject);
	void Update();
private:
	ball_ai* ballObject_ai;
	int playerNumber;
};