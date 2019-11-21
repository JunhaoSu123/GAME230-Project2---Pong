#include"Obstacle.h"
#include"Ball.h"
obstacle::obstacle() {
	this->Load("Obstacle.png");
	this->speed = 0.45f;
	this->velocity.y = 1.0f;
}
void obstacle::Update(sf::RenderWindow* window) {

	if (this->getPosition().y + this->getGlobalBounds().height / 2 >= window->getSize().y / 2 + 200)
	{
		this->velocity.y *= -1;
	}
	else if (this->getPosition().y + this->getGlobalBounds().height / 2 <= window->getSize().y / 2 - 200)
	{
		this->velocity.y *= -1;
	}
GameObject::Update();

if (this->getPosition().y < 0)
{
	this->move(0, 1);
}
if (this->getPosition().y + this->getGlobalBounds().height > 600)
{
	this->move(0, -1);
}

}