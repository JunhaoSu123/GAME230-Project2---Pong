#pragma once
#include"Paddle.h"

class obstacle : public paddle {
public:
	obstacle();
	void Update(sf::RenderWindow* window);
private:
	float speed;
};
