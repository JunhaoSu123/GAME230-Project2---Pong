#include "Ai.h"

ai::ai(int playerNumber)
{
	this->playerNumber = playerNumber;
	this->ballObject = ballObject;
	this->speed = 0.60f;


	switch (this->playerNumber)
	{
	case 0:
		this->Load("paddle1.png");
		break;
	default:
		this->Load("paddle2.png");
		break;
	}
}

void ai::SetBall(ball_ai* ballObject)
{
	this->ballObject = ballObject;
}

void ai::Update()
{
	if (this->ballObject != NULL)
	{
		if (this->getPosition().y + this->getGlobalBounds().height / 2 < this->ballObject->getPosition().y)
		{
			this->velocity.y = this->speed;
		}
		if (this->getPosition().y + this->getGlobalBounds().height / 2 > this->ballObject->getPosition().y)
		{
			this->velocity.y = -this->speed;
		}
	}
	GameObject::Update();

	if (this->getPosition().y < 0)
	{
		this->move(0, this->speed);
	}
	if (this->getPosition().y + this->getGlobalBounds().height > 600)
	{
		this->move(0, -this->speed);
	}
}