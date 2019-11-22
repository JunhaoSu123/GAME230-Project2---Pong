#pragma once
#include"Paddle.h"

class hole : public paddle {
public:
	hole();
	void Update(sf::RenderWindow* window);
private:
	float speed;
};
