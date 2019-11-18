#include "player.h"
#include"Game_State.h"
#include"Ball.h"

player::player(int playerNum)
{
	this->playerNum = playerNum;
	switch (this->playerNum)
	{
	case 0:
		this->Load("paddle1.png");
		break;
	default:
		this->Load("paddle2.png");
		break;
	}
}
//void player::Setball(ball* ballObject) {
	//this->ballObject = ballObject;
//}

void player::Update(){
	switch (this->playerNum)
	{
	case 0:
		this->velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
		break;
	case 1:
		this->velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
		break;
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