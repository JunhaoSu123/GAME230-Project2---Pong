#pragma once
#include"Paddle.h"

class player : public paddle {
public:
	player(int playerNum);
	void Update();
private:
	int playerNum;

};
//extern float paddleCenter;