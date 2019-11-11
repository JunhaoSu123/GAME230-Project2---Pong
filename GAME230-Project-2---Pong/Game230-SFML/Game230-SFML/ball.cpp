#include "Ball.h"
#include"Score.h"
#include"Game_State.h"
#include"Main_Menu.h"

ball::ball(score* score1, score* score2, player* player1, player* player2) {
	this->Load("Ball.png");

	this->score1 = score1;
	this->score2 = score2;

	this->player1 = player1;
	this->player2 = player2;

	this->velocity.x = 1.75f;
	this->velocity.y = -0.45f;

	this->bufferBounce = new sf::SoundBuffer();
	this->bufferBounce->loadFromFile("Sounds/WaterDrop.wav");
	this->soundBounce = new sf::Sound(*this->bufferBounce);

	this->bufferGoal = new sf::SoundBuffer();
	this->bufferGoal->loadFromFile("Sounds/Goal.wav");
	this->soundGoal = new sf::Sound(*this->bufferGoal);

}
void ball::Update(sf::RenderWindow* window) {
	if (this->CollisionCheck(this->player1) || this->CollisionCheck(this->player2)) {
		this->velocity.x *= -1.1f;
		this->soundBounce->play();
	}

	if (this->getPosition().y < 0 || this->getPosition().y > 565){
		this->velocity.y *= -1.0f;
		this->soundBounce->play();
	}

	if (this->getPosition().x < -10) {
		this->score2->PlusOne();
		this->soundGoal->play();
		this->setPosition(window->getSize().x / 2 - 15, window->getSize().y / 2 - 30);
		this->velocity.x = -0.75f;
	}

	if (this->getPosition().x >790) {
		this->score1->PlusOne();
		this->soundGoal->play();
		this->setPosition(window->getSize().x / 2 - 15, window->getSize().y / 2 - 30);
		this->velocity.x = 0.75f;
	}
	GameObject::Update();
}
ball::~ball() {
	delete this->bufferBounce;
	delete this->bufferGoal;
	delete this->soundBounce;
	delete this->soundGoal;
}