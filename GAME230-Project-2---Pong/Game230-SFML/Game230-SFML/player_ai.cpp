#include "player_ai.h"

player_ai::player_ai(int playerNumber)
{
	this->playerNumber = playerNumber;
	this->ballObject_ai = ballObject_ai;

	switch (this->playerNumber)
	{
	case 0:
		this->Load("Paddle1.png");
		break;
	default:
		this->Load("Paddle2.png");
		break;
	}
}
void player_ai::SetBall(ball_ai* ballObject_ai) {
	this->ballObject_ai = ballObject_ai;
}


void player_ai::Update()
{
	if (this->ballObject_ai != NULL)
	{
		if (this->getPosition().y + this->getGlobalBounds().height / 2 < this->ballObject_ai->getPosition().y)
		{
			this->move(0, 1);
		}
		if (this->getPosition().y + this->getGlobalBounds().height / 2 > this->ballObject_ai->getPosition().y)
		{
			this->move(0, -1);
		}
	}
	GameObject::Update();
	if (this->getPosition().y < 0)
	{
		this->move(0, 1.0f);
	}
	if (this->getPosition().y + this->getGlobalBounds().height > 600)
	{
		this->move(0, -1.0f);
	}
}