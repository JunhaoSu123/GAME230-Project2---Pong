#include"PowerUp.h"
#include"Ball.h"
powerup::powerup() {
	this->Load("Powerup.png");
}
void powerup::Update(sf::RenderWindow* window) {

	GameObject::Update();


}