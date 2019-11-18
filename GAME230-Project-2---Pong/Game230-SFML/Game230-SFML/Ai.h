#pragma once

#include "paddle.h"
#include "ball_ai.h"

class ai : public paddle
{
public:
	ai(int playerNumber);
	void SetBall(ball_ai* ballObject);
	void Update();
private:
	ball_ai* ballObject;
	int playerNumber;
	float speed;
};
