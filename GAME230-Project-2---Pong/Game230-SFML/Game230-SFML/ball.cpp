#include "Ball.h"
#include"Score.h"
#include"Game_State.h"
#include"Main_Menu.h"
#include "WinState.h"
#include"Player.h"
#include"Hole.h"

//float paddleCenter;
//float ballCenter;
//float bounce;
//float angle;
bool getOb = false;
bool getho = false;
bool whoWon;
ball::ball(score* score3, score* socre4, player* player1, player* player2, obstacle* ob, hole* ho) {
	this->Load("Ball.png");

	this->score3 = score3;
	this->socre4 = socre4;

	this->player1 = player1;
	this->player2 = player2;
	this->ob = ob;
	this->ho = ho;

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
	//ballCenter = this->getPosition().y + this->getGlobalBounds().height / 2;
	//bounce = (paddleCenter - ballCenter)/paddleCenter;
	//angle = bounce * 1.309f;
	if (this->velocity.x < 0 && this->CollisionCheck(this->player1)) {
		//this->velocity.x *= cos(angle);
		//this->velocity.y *= -sin(angle);
		this->velocity.x *= -1.05f;
		this->soundBounce->play();
		getOb = true;
		getho = true;
	}
	if (this->velocity.x > 0 && this->CollisionCheck(this->player2)) {
		//this->velocity.x *= cos(angle);
		//this->velocity.y *= -sin(angle);
		this->velocity.x *= -1.05f;
		this->soundBounce->play();
		getOb = true;
		getho = true;
	}

	if (obActive == true && getOb == true && this->CollisionCheck(this->ob)) {
		this->velocity.x *= -1.0f;
		this->soundBounce->play();
		getOb = false;
	}

	if (hoActive == true && getho == true && this->CollisionCheck(this->ho)) {
		if (this->velocity.x < 0 && this->velocity.y < 0) {
			this->velocity.y -= 0.7f;
			getho = false;
		}
		if (this->velocity.x < 0 && this->velocity.y > 0) {
			this->velocity.y += 0.7f;
			getho = false;
		}
		if (this->velocity.x > 0 && this->velocity.y < 0) {
			this->velocity.y -= 0.7f;
			getho = false;
		}
		if (this->velocity.x > 0 && this->velocity.y > 0) {
			this->velocity.y += 0.7f;
			getho = false;
		}
	}
	if (this->getPosition().y < 0 || this->getPosition().y > 565){
		this->velocity.y *= -1.0f;
		this->soundBounce->play();
	}

	if (this->getPosition().x < -10) {
		this->socre4->PlusOne();
		whoWon = true;
		getho = false;
		this->soundGoal->play();
		this->setPosition(window->getSize().x / 2-50, window->getSize().y / 2 - 30);
		this->velocity.x = -1.75f;
		this->velocity.y = -0.45f;
	}

	if (this->getPosition().x >790) {
		this->score3->PlusOne();
		whoWon = false;
		getho = false;
		this->soundGoal->play();
		this->setPosition(window->getSize().x / 2+2, window->getSize().y / 2 - 30);
		this->velocity.x = 1.75f;
		this->velocity.y = 0.45f;
	}
	GameObject::Update();
}
ball::~ball() {
	delete this->bufferBounce;
	delete this->bufferGoal;
	delete this->soundBounce;
	delete this->soundGoal;
}